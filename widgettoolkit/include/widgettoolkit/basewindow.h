#pragma once

#include <SDL.h>
#include <widgettoolkit/export.h>
#include <widgettoolkit/geometry.h>
#include <widgettoolkit/constants.h>
#include <widgettoolkit/types.h>
#include <widgettoolkit/inputevent.h>
#include <string>

namespace Wt {

using namespace std;

class BaseWindow {
public:
    BaseWindow(Rect contentRect, const string& title, long style);
    void SetTitle(const string& title);
    void SetRect(Rect rect);
    void SetContentRect(Rect rect);
    string GetTitle();
    Rect GetRect();
    Rect GetContentRect();
    SDL_Surface* GetSurface();
    SDL_Surface* GetContentSurface();
    void SetActive(bool active);
    void SetVisible(bool visible);
    void SetMaximizable(bool maximizable);
    void SetMinimizable(bool minimizable);
    void SetClosable(bool closable);
    bool IsActive();
    bool IsVisible();
    bool IsMaximizable();
    bool IsMinimizable();
    bool IsClosable();
    Rect GetCloseButtonRect();
    Rect GetMinimizeButtonRect();
    Rect GetMaximizeButtonRect();
    Rect GetTitleBarRect();
    int GetRightMargin();
    int GetLeftMargin();
    int GetTopMargin();
    int GetBottomMargin();
    bool IsMaximized();
    bool IsMinimized();
    void SetMaximized(bool miximize);
    void SetMinimized(bool minimize);
    void DrawContent(bool drawDecoration);
    void DrawContentSurface();
    void SetNeedsToBeClosed();
    bool NeedsToBeClosed();
    ~BaseWindow();

private:
    void CreateSurface();
    void ParseStyle();
    void CalculateMargins();
    void CalculateDecorationsMetrics();
    void DrawDecoration();

private:
    string mTitle;
    Rect mRect;
    Rect mContentRect;
    int mLeftMargin;
    int mRightMargin;
    int mTopMargin;
    int mBottomMargin;
    SDL_Surface* mSurface;
    SDL_Surface* mContentSurface;
    long mStyle;
    bool mMaximizable;
    bool mMinimizable;
    bool mClosable;
    bool mVisible;
    bool mActive;
    Rect mCloseButtonRect;
    Rect mMinimizeButtonRect;
    Rect mMaximizeButtonRect;
    Rect mTitleBarRect;
    bool mMaximized;
    bool mMinimized;
    Rect mRectBeforeMaximization;
    Rect mRectBeforeMinimization;
    bool mNeedsToBeClosed;

public:
    void* Window;
};

}