#!/bin/sh
# Run the interior-alias scan on a configured and built windows-x64 tree.
# usage: run.sh BUILD_DIR RECIPE OUT_DIR JOBS
# BUILD_DIR needs CMakeFiles/game.dir and compile_commands.json (configure with
# -DCMAKE_EXPORT_COMPILE_COMMANDS=ON). LLVM_BIN may name the directory of llvm-readobj
# and llvm-objdump. The committed tables are OUT_DIR/tables.
set -e
B=$1; R=$2; O=$3; J=$4
H=$(cd "$(dirname "$0")" && pwd)
mkdir -p "$O"
python3 "$H/scan_objects.py" "$B" "$O/objects.jsonl" "$J"
python3 "$H/i686_objects.py" "$B" "$O/i686" "$J"
python3 "$H/i686_sizes.py" "$O/i686/CMakeFiles/game.dir" "$O/i686.jsonl" "$J"
python3 "$H/scan_families.py" "$R" "$O/objects.jsonl" "$O/i686.jsonl" "$O/scan" "$H/owners.tsv"
python3 "$H/scan_tables.py" "$O/scan" "$O/tables"
