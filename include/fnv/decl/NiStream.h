#pragma once

class NiBinaryStream;
class NiObject;
class NiObjectGroup;
class NiTexture;
template <class> class NiPointer;

class NiStream {
public:
    // 0x00a632f0
    bool Load(char *, int);
    // 0x00a63330
    bool Load(::NiBinaryStream *);
    // 0x00a63380
    bool Save(::NiBinaryStream *);
    // 0x00a633d0
    void GetTexture(const char *, ::NiPointer< ::NiTexture> &);
    // 0x00a63430
    ::NiObject *GetLoadedObject();
    // 0x00a634e0
    ::NiObjectGroup *GetObjectGroup(unsigned int);
    // 0x00a635e0
    bool Save(char *&, int &);
    // 0x00a636b0
    bool GetLastLoadedFilePath(char *, unsigned int);
    // 0x00a636f0
    void SetStreamPath(const char *);
    // 0x00a644f0
    void ClearTopLevelObjects();
    // 0x00a64620
    ::NiObject *DeserializeObject();
    // 0x00a64700
    void SetLinkIDCount(unsigned int);
    // 0x00a64900
    static int RegisterObjectLoader(const char *, NiObject *(*)());
    // 0x00a64920
    static void RegisterPostProcess(void (*)(NiStream &, NiObject *));
    // 0x00a66370
    void InsertObject(::NiObject *);
};
