#!/bin/sh
# Census of one source tree: runs queries.cq over every unit of the game archive, then parse.py
# and fn_names.py.
#
#   run.sh BUILD_DIR SOURCE_ROOT RUN_DIR JOBS
#
# BUILD_DIR is a configured windows-x64 build tree with compile_commands.json
# (-DCMAKE_EXPORT_COMPILE_COMMANDS=ON) whose source tree is SOURCE_ROOT. RUN_DIR receives
# sites.tsv, names.tsv and summary.txt. CLANG_QUERY names the clang-query to run.
set -eu
BUILD=$1; SOURCE=$2; RUN=$3; JOBS=$4
HERE=$(cd "$(dirname "$0")" && pwd)
mkdir -p "$RUN/out"
: > "$RUN/exits.txt"
python3 - "$BUILD/compile_commands.json" "$RUN" <<'P'
import json, sys
game = [c for c in json.load(open(sys.argv[1])) if '/FoCMakeFiles/game.dir/' in c['command']]
json.dump(game, open(sys.argv[2] + '/game_commands.json', 'w'))
open(sys.argv[2] + '/units.txt', 'w').write(''.join(c['file'] + '\n' for c in game))
P
RUN=$RUN BUILD=$BUILD QUERIES=$HERE/queries.cq CLANG_QUERY=${CLANG_QUERY:-clang-query} export RUN BUILD QUERIES CLANG_QUERY
# NUL-separated arguments: some units have a space in their path.
awk '{printf "%d%c%s%c", NR, 0, $0, 0}' "$RUN/units.txt" | xargs -0 -n 2 -P "$JOBS" sh -c '
  "$CLANG_QUERY" -p "$BUILD" -f "$QUERIES" "$2" > "$RUN/out/$1.txt" 2> "$RUN/out/$1.err"
  echo "$1 $? $2" >> "$RUN/exits.txt"' census
python3 "$HERE/parse.py" "$RUN" "$SOURCE" "$BUILD"
python3 "$HERE/fn_names.py" "$RUN/game_commands.json" "$RUN/fn_sites.tsv" "$RUN/names.tsv" "$JOBS"
