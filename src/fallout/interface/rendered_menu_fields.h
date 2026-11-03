#pragma once

class NiCamera;
class Tile;

// The leading fields of FORenderedMenu (src/fallout/interface/forenderedmenu_decls.h), for code that
// reaches a rendered menu through a stand-in type.
struct RenderedMenuFields
{
    void* m_ppVirtualMethodTable;
    void* m_pMenuBackgroundScreenGeometry;
    void* m_pMenuRoot;
    void* m_pScreenGeometry;
    void* m_pDefaultTexture;
    void* m_pRenderedMenuObject;
    Tile* m_pFourthMenuObject;
    void* m_pMenuLight;
    void* m_pSecondaryMenuObject;
    NiCamera* m_pMenuLightParameters;
};
