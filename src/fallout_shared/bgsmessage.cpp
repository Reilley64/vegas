// fallout_shared/bgsmessage.cpp: BGSMessage, MessageCopyAccess, MessageCompare (16 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Dummy00501c30.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00482cb0_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00501c10_cls.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00680910_shell.h"
#include "fnv/decl/FUN_00680a70_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/decl/Twin_0086cf00.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004ff000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "bgsmessage_match_decls.h"
#include "BGSMessage.h"
#include "PerkButtonEntry.h"

class BGSMenuIcon : public TESForm
{
};

struct BGSMessageInitItemLocals
{
    PerkButtonEntry* button;
    int conditionErrors;
    int warningState;
    BSSimpleList<PerkButtonEntry*>* buttonList;
    unsigned int buttonIndex;
    unsigned int iconFormID;
};

// @fnv 0x00590530
BGSMessage::BGSMessage()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_MESG_ID)));
    ResetFormData();
}

// @fnv 0x005906a0
void BGSMessage::ResetFormData()
{
    pIcon = 0;
    iFlags = 1;
    m_uiDisplayDuration = 2;
}

// @fnv 0x005906d0
void BGSMessage::ClearData()
{
    reinterpret_cast<::Twin_0086cf00 *>(this)->SetD3DPixelShader((::GeometryRelatedType *const)(0));
    ClearButtons();
}

// @fnv 0x005906f0
void BGSMessage::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
    {
        return;
    }

    BGSMessageInitItemLocals locals;
    locals.iconFormID = reinterpret_cast<BGSMessageInitAccess*>(this)->GetIconFormID();
    if (locals.iconFormID)
    {
        ::ResolveFormID((unsigned int *)&(locals.iconFormID), GetFile(-1));
        reinterpret_cast<::Twin_0086cf00 *>(this)->SetD3DPixelShader((::GeometryRelatedType *const)(dynamic_cast<BGSMenuIcon*>(::FUN_004839c0(locals.iconFormID))));

        if (!reinterpret_cast<BGSMessageInitAccess*>(this)->GetIconFormID())
        {
            ::FUN_005b5e40();
        }
    }

    locals.buttonList =
        reinterpret_cast<BSSimpleList<PerkButtonEntry*>*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList());
    locals.buttonIndex = 0;
    while (locals.buttonList && !locals.buttonList->IsEmpty())
    {
        locals.button = (locals.buttonList->m_item);
        locals.buttonList = ((::BSSimpleList< ::PerkButtonEntry *> *)(reinterpret_cast<::Callees *>((locals.buttonList))->FUN_00726070()));
        locals.button->Conditions.InitItem(this);
        locals.warningState = ::FUN_0046e8a0();
        ::FUN_0043b2b0((bool)(reinterpret_cast<NiTexture*>(1)));
        ::FUN_004fffe0(0);
        ::FUN_0043b2b0((bool)(0));
        locals.conditionErrors = ::FUN_0046e8a0();
        ::FUN_004fffe0(locals.warningState);
        if (locals.conditionErrors)
        {
            ::FUN_005b5e40(
                );
        }
        ++locals.buttonIndex;
    }

    SetInitializationState(true);
}

struct BGSMessageLoadLocals
{
    char* buttonText;
    PerkButtonEntry* newButton;
    char* editorIDText;
    unsigned int iconFormID;
    int chunkID;
    PerkButtonEntry* currentButton;
    unsigned int unused;
};

// Removes every item from the button list, deleting each button until the list is empty.
// @fnv 0x005910d0
void BGSMessage::ClearButtons()
{
    while (!m_kButtonEntries.IsEmpty())
    {
        PerkButtonEntry* button = ((::PerkButtonEntry *)(new ((void *)&(m_kButtonEntries)) ::Vec3()));
        m_kButtonEntries.RemoveHead();
        delete button;
    }
}

struct FUN_00590d00_shell : public BGSMessage
{
    bool FUN_00590d00();
};

// @fnv 0x00590d00
bool FUN_00590d00_shell::FUN_00590d00()
{
    return (this->iFlags & 1) ? true : false;
}

struct FUN_00590ed0_shell : public BGSMessage
{
    bool IsFlagSet();
};

// @fnv 0x00590ed0
bool FUN_00590ed0_shell::IsFlagSet()
{
    return (this->iFlags & 2) ? true : false;
}

struct FUN_005911d0_shell : public BGSMessage
{
    void FUN_005911d0(PerkButtonEntry*);
};
// @fnv 0x00590880
bool BGSMessage::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);

    BGSMessageLoadLocals locals;
    locals.currentButton = 0;
    locals.unused = 0;
    while ((locals.chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (locals.chunkID)
        {
        case 0x44494445: {
            locals.editorIDText = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(locals.editorIDText), 0x200);
            SetEditorID_AtRuntime(locals.editorIDText);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x43534544:
            TESDescription::ReadDescriptionFromFile(static_cast<TESDescription*>(this), file);
            break;
        case 0x4c4c5546:
            ::ReadFullName(static_cast<TESFullName*>(this), file);
            break;
        case 0x4d414e49: {
            file->GetChunkData(&locals.iconFormID);
            reinterpret_cast<::Twin_0086cf00 *>(this)->SetD3DPixelShader((::GeometryRelatedType *const)(reinterpret_cast<BGSMenuIcon*>(locals.iconFormID)));
            break;
        }
        case 0x4d414e44:
            file->GetChunkData(&iFlags);
            break;
        case 0x4d414e54:
            file->GetChunkData(&m_uiDisplayDuration);
            break;
        case 0x54585449: {
            locals.buttonText = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(locals.buttonText), 0);
            locals.newButton = new PerkButtonEntry;
            reinterpret_cast<::TextString *>(&(locals.newButton->cButtonText))->FUN_004037f0(locals.buttonText, 0);
            reinterpret_cast<::FUN_005911d0_shell *>((reinterpret_cast<BGSMessageLoadAccess*>(this)))->FUN_005911d0(locals.newButton);
            locals.currentButton = locals.newButton;
            break;
        }
        case 0x41445443:
            if (locals.currentButton)
            {
                locals.currentButton->Conditions.Load(file);
            }
            break;
        default:
            break;
        }

        if (!file->NextChunk())
        {
            break;
        }
    }

    return true;
}

// If apItem is non-null, appends it to the BSSimpleList at offset 0x30 of this object.
// @fnv 0x005911d0
void FUN_005911d0_shell::FUN_005911d0(PerkButtonEntry* apItem)
{
    if (apItem != 0)
    {
        reinterpret_cast<::Callees *>((&this->m_kButtonEntries))->FUN_00905820((void *)&(apItem));
    }
}

struct FUN_00590e80_shell
{
    int data[0x38 / 4 + 1];
    void SetEnabled(bool enabled);
};

// Sets or clears bit 0 of the flag word at offset 0x38 according to enabled.
// @fnv 0x00590e80
void FUN_00590e80_shell::SetEnabled(bool enabled)
{
    enabled ? data[0x38 / 4] |= 1 : data[0x38 / 4] &= ~1;
}

struct X905e0
{
    void* DestroyIfFlagged(unsigned int);
};
struct FUN_00590ef0_shell
{
    int pad[14];
    int val38;
    void FUN_00590ef0(bool);
};
// @fnv 0x00590ef0
void FUN_00590ef0_shell::FUN_00590ef0(bool enabled)
{
    enabled ? val38 |= 2 : val38 &= ~2;
}

class B590610File;
class B590610MenuIcon;
class B590610Button;

template <class T> class B590610SimpleList
{
  public:
    ~B590610SimpleList();

    T m_item;
    B590610SimpleList* m_pkNext;
};

class B590610Form
{
  public:
    virtual ~B590610Form();
    virtual void ClearData();

    unsigned char m_cFormType;
    unsigned int m_iFormFlags;
    unsigned int m_iFormID;
    B590610File* m_pkSourceFile;
    void* m_pkNextSourceFile;
};

class B590610FullName
{
  public:
    virtual void Init();
    ~B590610FullName();

    const char* m_pcName;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
};

class B590610Description
{
  public:
    virtual void Init();

    unsigned int m_uiFileOffset;
};

class FUN_00590610_Message : public B590610Form, public B590610FullName, public B590610Description
{
  public:
    virtual ~FUN_00590610_Message();
    virtual void ClearData();

    B590610MenuIcon* m_pkIcon;
    B590610SimpleList<B590610Button*> m_kButtonList;
    unsigned int m_uiValue1;
    unsigned int m_uiDisplayTime;
};
// @fnv 0x005905e0
void* X905e0::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00590610_Message *>(this)->FUN_00590610_Message::~FUN_00590610_Message();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00590610
FUN_00590610_Message::~FUN_00590610_Message()
{
    ClearData();
}

struct MessageCopyAccess : public BGSMessage
{
    void CopyFromMessage(TESForm* form);
};

struct ButtonTextAccess
{
};

struct ConditionCopyAccess
{
};

// Clears the message data, copies icon, auto-display, message-box flag, quest and button list from form, then copies the base form.
// @fnv 0x00590d20
void MessageCopyAccess::CopyFromMessage(TESForm* form)
{
    BSSimpleList<PerkButtonEntry*>* node;
    ClearData();
    MessageCopyAccess* src = (MessageCopyAccess*)form;
    reinterpret_cast<::Twin_0086cf00 *>(this)->SetD3DPixelShader((::GeometryRelatedType *const)(((::BGSMenuIcon *)(reinterpret_cast<::BGSMessageInitAccess *>((((MessageCopyAccess*)form)))->GetIconFormID()))));
    reinterpret_cast<::FUN_00590e80_shell *>(this)->SetEnabled(reinterpret_cast<::FUN_00590d00_shell *>((src))->FUN_00590d00());
    reinterpret_cast<::FUN_00590ef0_shell *>(this)->FUN_00590ef0(reinterpret_cast<::FUN_00590ed0_shell *>((src))->IsFlagSet());
    reinterpret_cast<::FUN_00409480_shell *>(this)->FUN_00409480((::TESActorBase *)(::TESForm *)(((::TESForm *)(reinterpret_cast<::Twin_00639b40 *>((src))->GetEntryPoint()))));
    node = ((::BSSimpleList< ::PerkButtonEntry *> *)(reinterpret_cast<::TESTopicInfo *>((src))->GetAddTopicList()));
    while (node && !node->IsEmpty())
    {
        PerkButtonEntry* item = (node->m_item);
        node = ((::BSSimpleList< ::PerkButtonEntry *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        PerkButtonEntry* button = new PerkButtonEntry;
        reinterpret_cast<::FUN_00501c10_cls *>((((ButtonTextAccess*)&button->cButtonText)))->CallAndReturnSelf((int)&(item->cButtonText));
        reinterpret_cast<::FUN_00680a70_shell *>((((ConditionCopyAccess*)&button->Conditions)))->CopyConditions(&item->Conditions, (::PerkEntryConditionSet *)(false));
        reinterpret_cast<::FUN_005911d0_shell *>(this)->FUN_005911d0(button);
    }
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(form);
}

struct Component0bc0
{
    int unk00, unk04, unk08;
};
struct Description0bc0
{
    int unk00, unk04;
};
struct Icon0bc0
{
};
struct String0bc0
{
    int unk00, unk04;
};
struct Conditions0bc0
{
};
struct Button0bc0
{
    String0bc0 text;
    Conditions0bc0 conditions;
};
struct List0bc0
{
    bool FUN_008256d0();
};
struct Target0bc0
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Component0bc0 fullName;
    Description0bc0 description;
    Icon0bc0* icon;
    int unk30, unk34;
    unsigned int flags, time;
    void WriteToStream();
};
// @fnv 0x00590bc0
void Target0bc0::WriteToStream()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00482cb0_shell *>(&(description))->FUN_00482cb0();
    reinterpret_cast<::FUN_00487010_shell *>(&(fullName))->FUN_00487010();
    unsigned int id = ((::Icon0bc0 *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID())) ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::Icon0bc0 *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))))->FUN_0084e3a0())) : 0;
    ::FUN_00485910(0x4d414e49, id);
    ::FUN_00485910(0x4d414e44, flags);
    if (!reinterpret_cast<::FUN_00590d00_shell *>(this)->FUN_00590d00())
        ::FUN_00485910(0x4d414e54, time);
    List0bc0* node = ((::List0bc0 *)(reinterpret_cast<::TESTopicInfo *>(this)->GetAddTopicList()));
    while (node && !node->FUN_008256d0())
    {
        Button0bc0* button = ((::Button0bc0 *)((void *)(node)));
        node = ((::List0bc0 *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        if (((const char *)(::FUN_00559450((int *)&(button->text)))))
            ::FUN_004856f0((void *)(0x54585449), (void *)(((const char *)(::FUN_00559450((int *)&(button->text))))), (void *)(((int)(::FUN_0044a670(((const char *)(::FUN_00559450((int *)&(button->text))))))) + 1));
        else
            ::FUN_00485910(0x54585449, 0);
        reinterpret_cast<::FUN_00680910_shell *>(&(button->conditions))->ProcessItems();
    }
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

struct ButtonConditionView
{
};
struct ButtonView
{
    int text00, text04;
    ButtonConditionView conditions;
};
struct ButtonListView
{
    int FUN_005ae380();
    bool FUN_008256d0();
};
struct MessageCompare : BGSMessage
{
    bool IsNotEqual(TESForm*);
};
// @fnv 0x00590f40
bool MessageCompare::IsNotEqual(TESForm* form)
{
    MessageCompare* right = static_cast<MessageCompare*>(form);
    if (!right)
        return true;
    if (reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID() != reinterpret_cast<::BGSMessageInitAccess *>((right))->GetIconFormID())
        return true;
    if (reinterpret_cast<::FUN_00590d00_shell *>(this)->FUN_00590d00() != reinterpret_cast<::FUN_00590d00_shell *>((right))->FUN_00590d00())
        return true;
    if (reinterpret_cast<::FUN_00590ed0_shell *>(this)->IsFlagSet() != reinterpret_cast<::FUN_00590ed0_shell *>((right))->IsFlagSet())
        return true;
    if (((unsigned int)(reinterpret_cast<::Twin_00639b40 *>(this)->GetEntryPoint())) != ((unsigned int)(reinterpret_cast<::Twin_00639b40 *>((right))->GetEntryPoint())))
        return true;
    ButtonListView* left = ((::ButtonListView *)(reinterpret_cast<::TESTopicInfo *>(this)->GetAddTopicList()));
    ButtonListView* other = ((::ButtonListView *)(reinterpret_cast<::TESTopicInfo *>((right))->GetAddTopicList()));
    if (left->FUN_005ae380() != other->FUN_005ae380())
        return true;
    while (other && !other->FUN_008256d0() && left && !left->FUN_008256d0())
    {
        ButtonView* rhs = *((::ButtonView **)((void *)(other)));
        ButtonView* lhs = *((::ButtonView **)((void *)(left)));
        if (reinterpret_cast<::Dummy00501c30 *>((lhs))->FUN_00501c30((const char *)(rhs)))
            return true;
        if (reinterpret_cast<::PerkEntryConditionSet *>(&(lhs->conditions))->Compare((::PerkEntryConditionSet *)(::ButtonConditionView *)(&rhs->conditions)))
            return true;
        other = ((::ButtonListView *)(reinterpret_cast<::Callees *>((other))->FUN_00726070()));
        left = ((::ButtonListView *)(reinterpret_cast<::Callees *>((left))->FUN_00726070()));
    }
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(form))
        return true;
    return false;
}
