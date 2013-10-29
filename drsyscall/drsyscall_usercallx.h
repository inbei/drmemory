/* **********************************************************
 * Copyright (c) 2011-2013 Google, Inc.  All rights reserved.
 * **********************************************************/

/* Dr. Memory: the memory debugger
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; 
 * version 2.1 of the License, and no later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* Secondary system calls for:
 *   NtUserCallHwnd
 *   NtUserCallHwndLock
 *   NtUserCallHwndOpt
 *   NtUserCallHwndParam
 *   NtUserCallHwndParamLock
 *   NtUserCallMsgFilter
 *   NtUserCallNextHookEx
 *   NtUserCallNoParam
 *   NtUserCallOneParam
 *   NtUserCallTwoParam
 * Initial added as part of i#389.
 */

/* Numbers are for 7 platforms:
 * USERCALL(type, name, w2k, xp, 2003, vistaSP01, vistaSP2, w7, w8)
 *
 * We assume 64-bit matches 32-bit.
 *
 * FIXME i#728:
 * + get the syscall numbers for Windows 2000
 * + verify all the intermediate calls for Windows 7.
 *   for i#389 I verified calls at a number of points throughout the list.
 * + verify all the intermediate calls for Vista SP2.
 *   for i#819 I verified calls made by NtUserTests in app_suite.
 * + determine the currently-unknown calls: there are a small number whose names
 *   and params are unknown
 */

/* N.B.: this list must contain the same number of entries as syscall_usercall_info[]
 * in syscall_wingdi.c
 */
USERCALL(NtUserCallNoParam, CREATEMENU                     , NONE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00)
USERCALL(NtUserCallNoParam, CREATEMENUPOPUP                , NONE, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01)
USERCALL(NtUserCallNoParam, DISABLEPROCWNDGHSTING          , NONE, 0x02, 0x02, 0x06, 0x07, 0x07, 0x07)
USERCALL(NtUserCallNoParam, MSQCLEARWAKEMASK               , NONE, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03)
USERCALL(NtUserCallNoParam, ALLOWFOREGNDACTIVATION         , NONE, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02)
USERCALL(NtUserCallNoParam, CREATESYSTEMTHREADS            , NONE, NONE, NONE, 0x04, NONE, NONE, NONE)
/* XXX i#484: win7 seems to have added sthg here since the rest are all shifted; win8 removed it */
USERCALL(NtUserCallNoParam, UNKNOWN                        , NONE, NONE, NONE, NONE, 0x05, 0x05, NONE)
USERCALL(NtUserCallNoParam, DESTROY_CARET                  , NONE, 0x05, 0x05, 0x05, 0x06, 0x06, 0x05)
USERCALL(NtUserCallNoParam, GETDEVICECHANGEINFO            , NONE, 0x06, 0x06, 0x07, 0x08, 0x08, 0x07)
USERCALL(NtUserCallNoParam, GETIMESHOWSTATUS               , NONE, 0x07, 0x07, 0x08, 0x09, 0x09, 0x08)
USERCALL(NtUserCallNoParam, GETINPUTDESKTOP                , NONE, 0x08, 0x08, 0x09, 0x0a, 0x0a, 0x09)
USERCALL(NtUserCallNoParam, GETMESSAGEPOS                  , NONE, 0x09, 0x09, 0x0a, 0x0b, 0x0b, 0x0a)
USERCALL(NtUserCallNoParam, GETREMOTEPROCID                , NONE, 0x0a, 0x0a, NONE, NONE, NONE, NONE)
USERCALL(NtUserCallNoParam, HIDECURSORNOCAPTURE            , NONE, 0x0b, 0x0b, 0x0c, 0x0d, 0x0d, 0x0c)
USERCALL(NtUserCallNoParam, LOADCURSANDICOS                , NONE, 0x0c, 0x0c, 0x0d, 0x0e, 0x0e, 0x0d)
USERCALL(NtUserCallNoParam, PREPAREFORLOGOFF               , NONE, NONE, NONE, 0x0f, 0x10, 0x10, 0x0f)
USERCALL(NtUserCallNoParam, RELEASECAPTURE                 , NONE, 0x0d, 0x0d, 0x10, 0x11, 0x11, 0x10)
USERCALL(NtUserCallNoParam, RESETDBLCLICK                  , NONE, 0x0e, 0x0e, 0x11, 0x12, 0x12, 0x11)
USERCALL(NtUserCallNoParam, ZAPACTIVEANDFOUS               , NONE, 0x0f, 0x0f, 0x12, 0x13, 0x13, 0x12)
USERCALL(NtUserCallNoParam, REMOTECONSHDWSTOP              , NONE, 0x10, 0x10, 0x13, 0x14, 0x14, 0x13)
USERCALL(NtUserCallNoParam, REMOTEDISCONNECT               , NONE, 0x11, 0x11, 0x14, 0x15, 0x15, 0x14)
USERCALL(NtUserCallNoParam, REMOTELOGOFF                   , NONE, 0x12, 0x12, 0x15, 0x16, 0x16, 0x15)
USERCALL(NtUserCallNoParam, REMOTENTSECURITY               , NONE, 0x13, 0x13, 0x16, 0x17, 0x17, 0x16)
USERCALL(NtUserCallNoParam, REMOTESHDWSETUP                , NONE, 0x14, 0x14, 0x17, 0x18, 0x18, 0x17)
USERCALL(NtUserCallNoParam, REMOTESHDWSTOP                 , NONE, 0x15, 0x15, 0x18, 0x19, 0x19, 0x18)
USERCALL(NtUserCallNoParam, REMOTEPASSTHRUENABLE           , NONE, 0x16, 0x16, 0x19, 0x1a, 0x1a, 0x19)
USERCALL(NtUserCallNoParam, REMOTEPASSTHRUDISABLE          , NONE, 0x17, 0x17, 0x1a, 0x1b, 0x1b, 0x1a)
USERCALL(NtUserCallNoParam, REMOTECONNECTSTATE             , NONE, 0x18, 0x18, 0x1b, 0x1c, 0x1c, 0x1b)
USERCALL(NtUserCallNoParam, UPDATEPERUSERIMMENABLING       , NONE, 0x19, 0x19, 0x1c, 0x1d, 0x1d, 0x1c)
USERCALL(NtUserCallNoParam, USERPWRCALLOUTWORKER           , NONE, 0x1a, 0x1a, 0x1d, 0x1e, 0x1e, 0x1d)
USERCALL(NtUserCallNoParam, WAKERITFORSHTDWN               , NONE, NONE, NONE, 0x1e, 0x1f, 0x1f, 0x1e)
USERCALL(NtUserCallNoParam, INIT_MESSAGE_PUMP              , NONE, 0x1b, 0x1b, 0x1f, 0x20, 0x20, 0x1f)
USERCALL(NtUserCallNoParam, UNINIT_MESSAGE_PUMP            , NONE, 0x1c, 0x1c, 0x20, 0x21, 0x21, 0x20)
USERCALL(NtUserCallNoParam, LOADUSERAPIHOOK                , NONE, 0x1d, 0x1d, 0x0e, 0x0f, 0x0f, 0x0e)
/* FIXME i#1153: win8 added 2 somewhere between 0x05 and 0x24 */
USERCALL(NtUserCallOneParam, BEGINDEFERWNDPOS              , NONE, 0x1e, 0x1e, 0x21, 0x22, 0x22, 0x24)
USERCALL(NtUserCallOneParam, GETSENDMSGRECVR               , NONE, NONE, NONE, 0x22, 0x23, 0x23, 0x25)
USERCALL(NtUserCallOneParam, WINDOWFROMDC                  , NONE, 0x1f, 0x1f, 0x23, 0x24, 0x24, 0x26)
USERCALL(NtUserCallOneParam, ALLOWSETFOREGND               , NONE, 0x20, 0x20, 0x24, 0x25, 0x25, 0x27)
USERCALL(NtUserCallOneParam, CREATEEMPTYCUROBJECT          , NONE, 0x21, 0x21, 0x25, 0x26, 0x26, 0x28)
USERCALL(NtUserCallOneParam, CREATESYSTEMTHREADS           , NONE, 0x22, 0x22, NONE, 0x04, 0x04, 0x04)
USERCALL(NtUserCallOneParam, CSDDEUNINITIALIZE             , NONE, 0x23, 0x23, 0x26, 0x27, 0x27, 0x29)
USERCALL(NtUserCallOneParam, DIRECTEDYIELD                 , NONE, 0x24, 0x24, 0x27, 0x28, 0x28, 0x2a)
USERCALL(NtUserCallOneParam, ENUMCLIPBOARDFORMATS          , NONE, 0x25, 0x25, 0x28, 0x29, 0x29, 0x2b)
USERCALL(NtUserCallOneParam, GETCURSORPOS                  , NONE, 0x26, 0x26, NONE, NONE, NONE, NONE)
USERCALL(NtUserCallOneParam, GETINPUTEVENT                 , NONE, 0x27, 0x27, 0x29, 0x2a, 0x2a, 0x2c)
USERCALL(NtUserCallOneParam, GETKEYBOARDLAYOUT             , NONE, 0x28, 0x28, 0x2a, 0x2b, 0x2b, 0x2d)
USERCALL(NtUserCallOneParam, GETKEYBOARDTYPE               , NONE, 0x29, 0x29, 0x2b, 0x2c, 0x2c, 0x2e)
USERCALL(NtUserCallOneParam, GETPROCDEFLAYOUT              , NONE, 0x2a, 0x2a, 0x2c, 0x2d, 0x2d, 0x2f)
USERCALL(NtUserCallOneParam, GETQUEUESTATUS                , NONE, 0x2b, 0x2b, 0x2d, 0x2e, 0x2e, 0x30)
USERCALL(NtUserCallOneParam, GETWINSTAINFO                 , NONE, 0x2c, 0x2c, 0x2e, 0x2f, 0x2f, 0x31)
USERCALL(NtUserCallOneParam, HANDLESYSTHRDCREATFAIL        , NONE, 0x2d, 0x2d, 0x0b, 0x0c, 0x0c, 0x0c)
USERCALL(NtUserCallOneParam, LOCKFOREGNDWINDOW             , NONE, 0x2e, 0x2e, 0x2f, 0x30, 0x30, 0x32)
USERCALL(NtUserCallOneParam, LOADFONTS                     , NONE, 0x2f, 0x2f, 0x30, 0x31, 0x31, 0x33)
USERCALL(NtUserCallOneParam, MAPDEKTOPOBJECT               , NONE, 0x30, 0x30, 0x31, 0x32, 0x32, 0x34)
USERCALL(NtUserCallOneParam, MESSAGEBEEP                   , NONE, 0x31, 0x31, 0x32, 0x33, 0x33, 0x35)
USERCALL(NtUserCallOneParam, PLAYEVENTSOUND                , NONE, 0x32, 0x32, 0x33, 0x34, 0x34, 0x36)
USERCALL(NtUserCallOneParam, POSTQUITMESSAGE               , NONE, 0x33, 0x33, 0x34, 0x35, 0x35, 0x37)
USERCALL(NtUserCallOneParam, PREPAREFORLOGOFF              , NONE, 0x34, 0x34, 0x0f, 0x10, 0x10, 0x10)
USERCALL(NtUserCallOneParam, REALIZEPALETTE                , NONE, 0x35, 0x35, 0x35, 0x36, 0x36, 0x38)
USERCALL(NtUserCallOneParam, REGISTERLPK                   , NONE, 0x36, 0x36, 0x36, 0x37, 0x37, 0x39)
USERCALL(NtUserCallOneParam, REGISTERSYSTEMTHREAD          , NONE, NONE, NONE, 0x37, 0x38, 0x38, 0x3a)
USERCALL(NtUserCallOneParam, REMOTERECONNECT               , NONE, 0x37, 0x37, 0x38, 0x39, 0x39, 0x3b)
USERCALL(NtUserCallOneParam, REMOTETHINWIRESTATUS          , NONE, 0x38, 0x38, 0x39, 0x3a, 0x3a, 0x3c)
USERCALL(NtUserCallOneParam, RELEASEDC                     , NONE, 0x39, 0x39, 0x3a, 0x3b, 0x3b, 0x3d)
USERCALL(NtUserCallOneParam, REMOTENOTIFY                  , NONE, NONE, NONE, 0x3b, 0x3c, 0x3c, 0x3e)
USERCALL(NtUserCallOneParam, REPLYMESSAGE                  , NONE, 0x3a, 0x3a, 0x3c, 0x3d, 0x3d, 0x3f)
USERCALL(NtUserCallOneParam, SETCARETBLINKTIME             , NONE, 0x3b, 0x3b, 0x3d, 0x3e, 0x3e, 0x40)
USERCALL(NtUserCallOneParam, SETDBLCLICKTIME               , NONE, 0x3c, 0x3c, 0x3e, 0x3f, 0x3f, 0x41)
USERCALL(NtUserCallOneParam, SETIMESHOWSTATUS              , NONE, 0x3d, 0x3d, NONE, NONE, NONE, NONE)
USERCALL(NtUserCallOneParam, SETMESSAGEEXTRAINFO           , NONE, 0x3e, 0x3e, 0x3f, 0x40, 0x40, 0x42)
USERCALL(NtUserCallOneParam, SETPROCDEFLAYOUT              , NONE, 0x3f, 0x3f, 0x40, 0x41, 0x41, 0x43)
USERCALL(NtUserCallOneParam, SETWATERMARKSTRINGS           , NONE, NONE, NONE, 0x41, 0x42, 0x42, 0x44)
USERCALL(NtUserCallOneParam, SHOWCURSOR                    , NONE, 0x40, 0x40, 0x42, 0x43, 0x43, 0x45)
USERCALL(NtUserCallOneParam, SHOWSTARTGLASS                , NONE, 0x41, 0x41, 0x43, 0x44, 0x44, 0x46)
USERCALL(NtUserCallOneParam, SWAPMOUSEBUTTON               , NONE, 0x42, 0x42, 0x44, 0x45, 0x45, 0x47)
USERCALL(NtUserCallOneParam, UNKNOWNA                      , NONE, 0x43, 0x43, 0x45, 0x46, 0x46, 0x48)
USERCALL(NtUserCallOneParam, UNKNOWNB                      , NONE, 0x44, 0x44, NONE, NONE, NONE, NONE)
USERCALL(NtUserCallHwnd, DEREGISTERSHELLHOOKWINDOW         , NONE, 0x45, 0x45, 0x46, 0x47, 0x47, 0x47)
USERCALL(NtUserCallHwnd, DWP_GETENABLEDPOPUP               , NONE, 0x46, 0x46, 0x47, 0x48, 0x48, 0x48)
USERCALL(NtUserCallHwnd, GETWNDCONTEXTHLPID                , NONE, 0x47, 0x47, 0x48, 0x49, 0x49, 0x49)
USERCALL(NtUserCallHwnd, REGISTERSHELLHOOKWINDOW           , NONE, 0x48, 0x48, 0x49, 0x4a, 0x4a, 0x4a)
USERCALL(NtUserCallHwnd, UNKNOWN                           , NONE, 0x49, 0x49, 0x4a, 0x4b, 0x4b, 0x4b)
USERCALL(NtUserCallHwndOpt, SETPROGMANWINDOW               , NONE, 0x4a, 0x4a, 0x4b, 0x4c, 0x4c, 0x4c)
USERCALL(NtUserCallHwndOpt, SETTASKMANWINDOW               , NONE, 0x4b, 0x4b, 0x4c, 0x4d, 0x4d, 0x4d)
USERCALL(NtUserCallHwndParam, GETCLASSICOCUR               , NONE, 0x4c, 0x4c, 0x4d, 0x4e, 0x4e, 0x4e)
USERCALL(NtUserCallHwndParam, CLEARWINDOWSTATE             , NONE, 0x4d, 0x4d, 0x4e, 0x4f, 0x4f, 0x4f)
USERCALL(NtUserCallHwndParam, KILLSYSTEMTIMER              , NONE, 0x4e, 0x4e, 0x4f, 0x50, 0x50, 0x50)
USERCALL(NtUserCallHwndParam, SETDIALOGPOINTER             , NONE, 0x4f, 0x4f, 0x50, 0x51, 0x51, 0x51)
USERCALL(NtUserCallHwndParam, SETVISIBLE                   , NONE, 0x50, 0x50, 0x51, 0x52, 0x52, 0x52)
USERCALL(NtUserCallHwndParam, SETWNDCONTEXTHLPID           , NONE, 0x51, 0x51, 0x52, 0x53, 0x53, 0x53)
USERCALL(NtUserCallHwndParam, SETWINDOWSTATE               , NONE, 0x52, 0x52, 0x53, 0x54, 0x54, 0x54)
USERCALL(NtUserCallHwndLock, WINDOWHASSHADOW               , NONE, 0x53, 0x53, 0x54, 0x55, 0x55, 0x55)
USERCALL(NtUserCallHwndLock, ARRANGEICONICWINDOWS          , NONE, 0x54, 0x54, 0x55, 0x56, 0x56, 0x56)
/* FIXME i#1153: on win8, 4 more added between 0x45 and 0x5d */
USERCALL(NtUserCallHwndLock, DRAWMENUBAR                   , NONE, 0x55, 0x55, 0x56, 0x57, 0x57, 0x5d)
USERCALL(NtUserCallHwndLock, CHECKIMESHOWSTATUSINTHRD      , NONE, 0x56, 0x56, 0x57, 0x58, 0x58, 0x5e)
USERCALL(NtUserCallHwndLock, GETSYSMENUHANDLE              , NONE, 0x57, 0x57, 0x58, 0x59, 0x59, 0x5f)
USERCALL(NtUserCallHwndLock, REDRAWFRAME                   , NONE, 0x58, 0x58, 0x59, 0x5a, 0x5a, 0x60)
USERCALL(NtUserCallHwndLock, REDRAWFRAMEANDHOOK            , NONE, 0x59, 0x59, 0x5a, 0x5b, 0x5b, 0x61)
USERCALL(NtUserCallHwndLock, SETDLGSYSMENU                 , NONE, 0x5a, 0x5a, 0x5b, 0x5c, 0x5c, 0x62)
USERCALL(NtUserCallHwndLock, SETFOREGROUNDWINDOW           , NONE, 0x5b, 0x5b, 0x5c, 0x5d, 0x5d, 0x63)
USERCALL(NtUserCallHwndLock, SETSYSMENU                    , NONE, 0x5c, 0x5c, 0x5d, 0x5e, 0x5e, 0x64)
USERCALL(NtUserCallHwndLock, UPDATECKIENTRECT              , NONE, 0x5d, 0x5d, 0x5e, 0x5f, 0x5f, 0x65)
USERCALL(NtUserCallHwndLock, UPDATEWINDOW                  , NONE, 0x5e, 0x5e, 0x5f, 0x60, 0x60, 0x66)
USERCALL(NtUserCallHwndLock, UNKNOWN                       , NONE, 0x5f, 0x5f, 0x60, 0x61, 0x61, 0x67)
USERCALL(NtUserCallTwoParam, ENABLEWINDOW                  , NONE, 0x60, 0x60, 0x61, 0x62, 0x62, 0x68)
USERCALL(NtUserCallTwoParam, REDRAWTITLE                   , NONE, 0x61, 0x61, 0x62, 0x63, 0x63, 0x69)
USERCALL(NtUserCallTwoParam, SHOWOWNEDPOPUPS               , NONE, 0x62, 0x62, 0x63, 0x64, 0x64, 0x6a)
USERCALL(NtUserCallTwoParam, SWITCHTOTHISWINDOW            , NONE, 0x63, 0x63, 0x64, 0x65, 0x65, 0x6b)
USERCALL(NtUserCallTwoParam, UPDATEWINDOWS                 , NONE, 0x64, 0x64, 0x65, 0x66, 0x66, 0x6c)
USERCALL(NtUserCallHwndLockParam, VALIDATERGN              , NONE, 0x65, 0x65, 0x66, 0x67, 0x67, 0x6d)
/* FIXME i#1153: on win8, 1 more added between 0x5d and 0x6f */
USERCALL(NtUserCallTwoParam, CHANGEWNDMSGFILTER            , NONE, NONE, NONE, 0x67, 0x68, 0x68, 0x6f)
USERCALL(NtUserCallTwoParam, GETCURSORPOS                  , NONE, NONE, NONE, 0x68, 0x69, 0x69, 0x70)
USERCALL(NtUserCallTwoParam, GETHDEVNAME                   , NONE, 0x66, 0x66, 0x69, 0x6a, 0x6a, 0x71)
USERCALL(NtUserCallTwoParam, INITANSIOEM                   , NONE, 0x67, 0x67, 0x6a, 0x6b, 0x6b, 0x72)
USERCALL(NtUserCallTwoParam, NLSSENDIMENOTIFY              , NONE, 0x68, 0x68, 0x6b, 0x6c, 0x6c, 0x73)
USERCALL(NtUserCallTwoParam, REGISTERGHSTWND               , NONE, NONE, NONE, 0x6c, 0x6d, 0x6d, 0x74)
USERCALL(NtUserCallTwoParam, REGISTERLOGONPROCESS          , NONE, 0x69, 0x69, 0x6d, 0x6e, 0x6e, 0x75)
USERCALL(NtUserCallTwoParam, REGISTERSYSTEMTHREAD          , NONE, 0x6a, 0x6a, NONE, NONE, NONE, NONE)
USERCALL(NtUserCallTwoParam, REGISTERSBLFROSTWND           , NONE, NONE, NONE, 0x6e, 0x6f, 0x6f, 0x76)
USERCALL(NtUserCallTwoParam, REGISTERUSERHUNGAPPHANDLERS   , NONE, 0x6b, 0x6b, 0x6f, 0x70, 0x70, 0x77)
USERCALL(NtUserCallTwoParam, SHADOWCLEANUP                 , NONE, 0x6c, 0x6c, 0x70, 0x71, 0x71, 0x78)
USERCALL(NtUserCallTwoParam, REMOTESHADOWSTART             , NONE, 0x6d, 0x6d, 0x71, 0x72, 0x72, 0x79)
USERCALL(NtUserCallTwoParam, SETCARETPOS                   , NONE, 0x6e, 0x6e, 0x72, 0x73, 0x73, 0x7a)
USERCALL(NtUserCallTwoParam, SETCURSORPOS                  , NONE, 0x6f, 0x6f, 0x73, 0x74, 0x74, 0x7b)
USERCALL(NtUserCallTwoParam, SETPHYSCURSORPOS              , NONE, NONE, NONE, 0x74, 0x75, 0x75, 0x7c)
USERCALL(NtUserCallTwoParam, UNHOOKWINDOWSHOOK             , NONE, 0x70, 0x70, 0x75, 0x76, 0x76, 0x7d)
USERCALL(NtUserCallTwoParam, WOWCLEANUP                    , NONE, 0x71, 0x71, 0x76, 0x77, 0x77, 0x7e)
