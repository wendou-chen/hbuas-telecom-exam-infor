#include "key_server.h"
#include "common.h"
#include "system.h"

tKeyScan g_key1;
tKeyScan g_key2;
tKeyScan g_key3;
tKeyScan g_key4;
tKeyScan g_key5;

void Key_Init(void)
{
}

void Key_ScanStatus(tKeyScan* pKey)
{
    (void)pKey;
}

BOOL Key_IsDown(tKeyScan* pKey)
{
    (void)pKey;
    return FALSE;
}

BOOL Key_IsUp(tKeyScan* pKey)
{
    (void)pKey;
    return FALSE;
}

BOOL Key_IsLongDown(tKeyScan* pKey, u32 timeStep)
{
    (void)pKey;
    (void)timeStep;
    return FALSE;
}
