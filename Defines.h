#pragma once
const int nFILES     = 6;
const int nCOLUMNES  = 7;

const int nMESES     = 12;
const int nMODULOS   = 2;
const int nNOMBREMES = 16;

const int GRID_Y = 80;
const int GRID_X = 128;
const int HEADER_LINE_SZ = 23;

typedef char *charPtr;
typedef int  *intPtr;

typedef int  VectorDiasMes[nMESES];
typedef int  VectorModulosMes[nMODULOS];
typedef int  VectorModulosMesInfo[nMODULOS][nMESES];

typedef char VectorHeader[HEADER_LINE_SZ];
typedef char VectorNombreMes[nMESES][nNOMBREMES];
