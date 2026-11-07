#pragma once

// Public mathematical values shared by the renderer and native D3DX replacements.
class _D3DMATRIX
{
public:
    union
    {
        struct
        {
            float _11, _12, _13, _14;
            float _21, _22, _23, _24;
            float _31, _32, _33, _34;
            float _41, _42, _43, _44;
        };
        float m[4][4];
    };
};

struct D3DXMATRIX : public _D3DMATRIX
{
};

struct D3DXVECTOR4
{
    float x, y, z, w;

    D3DXVECTOR4() = default;
    D3DXVECTOR4(float xValue, float yValue, float zValue, float wValue)
        : x(xValue), y(yValue), z(zValue), w(wValue)
    {
    }
};
