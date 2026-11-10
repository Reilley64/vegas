// Setting collections and SettingT, the setting that adds itself to its collection.
#ifndef FNV_SETTINGT_H
#define FNV_SETTINGT_H
#include "Setting.h"

template <class T> class NiTPrimitiveArray;

template <class T> class SettingCollection
{
  public:
    SettingCollection();
    virtual ~SettingCollection();
    virtual void Add(T* setting);
    virtual void Remove(T* setting);
    virtual unsigned int GetViewerStrings(NiTPrimitiveArray<char*>* strings);
    virtual bool WriteSetting(T& setting);
    virtual bool ReadSetting(T& setting);
    virtual bool Open(bool write);
    virtual bool Close();
    virtual bool WriteAllSettings();
    virtual bool ReadAllSettings();

    char m_acPathBuffer[260];
    void* pHandle;
};

template <class T> class SettingCollectionList : public SettingCollection<T>
{
  public:
    SettingCollectionList();
    virtual ~SettingCollectionList();
    virtual void Add(T* setting);
    virtual void Remove(T* setting);
    virtual unsigned int GetViewerStrings(NiTPrimitiveArray<char*>* strings);
    virtual bool WriteAllSettings();
    virtual bool ReadAllSettings();
    bool Get(const char* key, T*& result);
    T* GetPtr(const char* key);
    BSSimpleList<T*>* Head();
    BSSimpleList<T*>* Next(BSSimpleList<T*>* position);

    BSSimpleList<T*> m_kSettingList;
};

class INISettingCollection : public SettingCollectionList<Setting>
{
  public:
    INISettingCollection();
    virtual ~INISettingCollection();
    virtual unsigned int GetViewerStrings(NiTPrimitiveArray<char*>* strings);
    virtual bool WriteSetting(Setting& setting);
    virtual bool ReadSetting(Setting& setting);
    virtual bool Open(bool write);
    virtual bool Close();
};

class INIPrefSettingCollection : public INISettingCollection
{
  public:
    INIPrefSettingCollection();
    virtual ~INIPrefSettingCollection();
};

struct GameSettingCollection : public SettingCollection<Setting>
{
};

// Collections known only by the address of their pointer; each getter creates it on first use.
class SettingCollection_011f35a4 : public SettingCollection<Setting>
{
};

class SettingCollection_011cc694 : public SettingCollection<Setting>
{
};

class SettingCollection_01204368 : public SettingCollection<Setting>
{
};

template <class Collection> class SettingT : public Setting
{
  public:
    SettingT(const char* key, float value);
    SettingT(const char* key, int value);
    SettingT(const char* key, char* value);
    SettingT(const char* key, const char* value);
    SettingT(const char* key, bool value);
    virtual ~SettingT();
    static Collection* GetCollection();

  protected:
    static Collection* ms_pCollection;
    static void EnsureCollection();
};

template <> GameSettingCollection* SettingT<GameSettingCollection>::GetCollection();
template <> void SettingT<INISettingCollection>::EnsureCollection();
template <> INISettingCollection* SettingT<INISettingCollection>::GetCollection();
template <> INIPrefSettingCollection* SettingT<INIPrefSettingCollection>::GetCollection();
template <> SettingCollection_011f35a4* SettingT<SettingCollection_011f35a4>::GetCollection();
template <> SettingCollection_011cc694* SettingT<SettingCollection_011cc694>::GetCollection();
template <> SettingCollection_01204368* SettingT<SettingCollection_01204368>::GetCollection();

#endif
