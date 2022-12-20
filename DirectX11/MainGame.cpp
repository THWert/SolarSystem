#include "framework.h"
#include "MainGame.h"

MainGame::~MainGame()
{
}

void MainGame::Init()
{
    //MemDc 메모리상의 dc를 하나 더 추가
    HBITMAP	 m_hOldBitmap, m_hBitmap;
    HDC	hdc = GetDC(g_hwnd); //기존 핸들
    g_MemDC = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 800, 600);
    m_hOldBitmap = (HBITMAP)SelectObject(g_MemDC, m_hBitmap);
    ReleaseDC(g_hwnd, hdc);

    rc1.position.x = 400.0f;
    rc1.position.y = 300.0f;
    rc1.scale = Vector2(100.0f, 100.0f);
    rc1.rotation = 0.0f;
    rc1.isAxis = true;

    rc2.position.x = 400.0f;
    rc2.position.y = 300.0f;
    rc2.scale = Vector2(100.0f, 100.0f);
    rc2.rotation = 0.0f;
    rc2.isAxis = false;

    rc3.position.x = 400.0f;
    rc3.position.y = 300.0f;
    rc3.scale = Vector2(100.0f, 100.0f);
    rc3.rotation = 0.0f;
    rc3.isAxis = false;

    rc4.position.x = 400.0f;
    rc4.position.y = 300.0f;
    rc4.scale = Vector2(100.0f, 100.0f);
    rc4.rotation = 0.0f;
    rc4.isAxis = false;

    rc5.position.x = 400.0f;
    rc5.position.y = 300.0f;
    rc5.scale = Vector2(100.0f, 100.0f);
    rc5.rotation = 0.0f;
    rc5.isAxis = false;

    cc1.position.x = 100.0f;
    cc1.position.y = 100.0f;
    cc1.scale = Vector2(10.0f, 10.0f);
    cc1.rotation = 0.0f;
    cc1.isAxis = true;

    cc2.position.x = -150.0f;
    cc2.position.y = 150.0f;
    cc2.scale = Vector2(10.0f, 10.0f);
    cc2.rotation = 0.0f;
    cc2.isAxis = true;

    cc3.position.x = 200.0f;
    cc3.position.y = -200.0f;
    cc3.scale = Vector2(10.0f, 10.0f);
    cc3.rotation = 0.0f;
    cc3.isAxis = true;

    cc4.position.x = -250.0f;
    cc4.position.y = -250.0f;
    cc4.scale = Vector2(10.0f, 10.0f);
    cc4.rotation = 0.0f;
    cc4.isAxis = true;

    //cc의 부모는 rc 다
    cc1.P = &rc2.RT;
    cc2.P = &rc3.RT;
    cc3.P = &rc4.RT;
    cc4.P = &rc5.RT;
}

void MainGame::Update()
{
    if (INPUT->KeyPress(VK_UP))
    {
        cc1.position += UP * 200.0f * ToRadian * DELTA;
    }
    if (INPUT->KeyPress(VK_DOWN))
    {
        cc1.position += DOWN * 200.0f * DELTA;
    }
    if (INPUT->KeyPress(VK_LEFT))
    {
        cc1.position += LEFT * 200.0f * DELTA;
    }
    if (INPUT->KeyPress(VK_RIGHT))
    {
        cc1.position += RIGHT * 200.0f * DELTA;
    }

    cc1.rotation += 120.0f * ToRadian * DELTA;
    cc2.rotation -= 200.0f * ToRadian * DELTA;
    cc3.rotation += 280.0f * ToRadian * DELTA;
    cc4.rotation -= 360.0f * ToRadian * DELTA;

    rc2.rotation += 120.0f * ToRadian * DELTA;
    rc3.rotation -= 240.0f * ToRadian * DELTA;
    rc4.rotation += 360.0f * ToRadian * DELTA;
    rc5.rotation -= 480.0f * ToRadian * DELTA;

    rc1.Update();
    rc2.Update();
    rc3.Update();
    rc4.Update();
    rc5.Update();

    cc1.Update();
    cc2.Update();
    cc3.Update();
    cc4.Update();


    //키가 눌렸을 때 wm_paint 를 발생 시켜라
    InvalidateRect(g_hwnd, NULL, false);
}

void MainGame::Render()
{
    PAINTSTRUCT ps;
    //hdc-> 도화지
    g_hdc = BeginPaint(g_hwnd, &ps);

    //바탕색 깔기
    PatBlt(g_MemDC, 0, 0, 800, 600, WHITENESS);
    string FPS = "FPS : " + to_string(TIMER->GetFPS());
    TextOutA(g_MemDC, 0, 0, FPS.c_str(), FPS.size());

    rc1.Render();

    cc1.Render();
    cc2.Render();
    cc3.Render();
    cc4.Render();

    //고속 복사 g_MemDC에서 g_hdc로
    BitBlt(g_hdc, 0, 0, 800, 600, g_MemDC, 0, 0, SRCCOPY);

    EndPaint(g_hwnd, &ps);
}