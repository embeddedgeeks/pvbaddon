//###############################################################
//# mask1_slots.h for ProcessViewServer created: Mi Sep 16 09:47:34 2009
//# please fill out these slots
//# here you find all possible events
//# Yours: Lehrig Software Engineering
//###############################################################

// todo: uncomment me if you want to use this data aquisiton
// also uncomment this classes in main.cpp and pvapp.h
// also remember to uncomment rllib in the project file
//extern rlModbusClient     modbus;
//extern rlSiemensTCPClient siemensTCP;
//extern rlPPIClient        ppi;

#define DELTA 10

typedef struct // (todo: define your data structure here)
{
  rlSvgAnimator svgAnimator;
}
DATA;

static int drawSVG1(PARAM *p, int id, DATA *d)
{
  if(d == NULL) return -1;
  if(d->svgAnimator.isModified == 0) return 0;
  printf("writeSocket\n");
  gBeginDraw(p,id);
  d->svgAnimator.writeSocket();
  gEndDraw(p);
  return 0;
}

static int slotInit(PARAM *p, DATA *d)
{
  if(p == NULL || d == NULL) return -1;
  //memset(d,0,sizeof(DATA));

  // load HTML
  pvDownloadFile(p,"icon32x32.png");
  pvDownloadFile(p,"upperWidget.html");
  pvDownloadFile(p,"leftWidget.html");
  pvSetSource(p,upperWidget,"upperWidget.html");
  pvSetSource(p,leftWidget,"leftWidget.html");

  // load SVG
  d->svgAnimator.setSocket(&p->s);
  d->svgAnimator.setId(centerWidget);
  d->svgAnimator.read("test.svg");

  // keep aspect ratio of SVG
  pvSetZoomX(p, centerWidget, -1.0f);
  pvSetZoomY(p, centerWidget, -1.0f);

  // draw SVG
  drawSVG1(p,centerWidget,d);

  // download icons
  pvDownloadFile(p,"1center.png");
  pvDownloadFile(p,"1uparrow.png");
  pvDownloadFile(p,"1downarrow.png");
  pvDownloadFile(p,"1leftarrow.png");
  pvDownloadFile(p,"1rightarrow.png");
  pvDownloadFile(p,"1center2.png");
  pvDownloadFile(p,"1uparrow2.png");
  pvDownloadFile(p,"1downarrow2.png");
  pvDownloadFile(p,"1leftarrow2.png");
  pvDownloadFile(p,"1rightarrow2.png");

  // set sliderZoom to 100 percent
  pvSetValue(p,sliderZoom,100);

  pvHtmlOrSvgDump(p,upperWidget,"dump.html");
  pvClientCommand(p,"html","dump.html");
  return 0;
}

static int slotNullEvent(PARAM *p, DATA *d)
{
  if(p == NULL || d == NULL) return -1;
  return 0;
}

static int slotButtonEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  if     (id == iCenter)
  {
    pvSetImage(p,iCenter,"1center2.png");
    d->svgAnimator.zoomCenter(1.0f);
    d->svgAnimator.setMouseXY0(0,0);
    d->svgAnimator.setXY0(0.0f,0.0f);
    d->svgAnimator.moveMainObject(0,0);
    drawSVG1(p,centerWidget,d);
    pvSetValue(p,sliderZoom,100);
  }
  else if(id == iUp)     
  {
    pvSetImage(p,iUp,"1uparrow2.png");
    d->svgAnimator.setMouseXY0(0,0);
    d->svgAnimator.moveMainObject(0,-DELTA);
    drawSVG1(p,centerWidget,d);
  }
  else if(id == iDown)   
  {
    pvSetImage(p,iDown,"1downarrow2.png");
    d->svgAnimator.setMouseXY0(0,0);
    d->svgAnimator.moveMainObject(0,DELTA);
    drawSVG1(p,centerWidget,d);
  }
  else if(id == iLeft)   
  {
    pvSetImage(p,iLeft,"1leftarrow2.png");
    d->svgAnimator.setMouseXY0(0,0);
    d->svgAnimator.moveMainObject(-DELTA,0);
    drawSVG1(p,centerWidget,d);
  }
  else if(id == iRight)  
  {
    pvSetImage(p,iRight,"1rightarrow2.png");
    d->svgAnimator.setMouseXY0(0,0);
    d->svgAnimator.moveMainObject(DELTA,0);
    drawSVG1(p,centerWidget,d);
  }
  return 0;
}

static int slotButtonPressedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotButtonReleasedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  if     (id == iCenter) pvSetImage(p,iCenter,"1center.png");
  else if(id == iUp)     pvSetImage(p,iUp,    "1uparrow.png");
  else if(id == iDown)   pvSetImage(p,iDown,  "1downarrow.png");
  else if(id == iLeft)   pvSetImage(p,iLeft,  "1leftarrow.png");
  else if(id == iRight)  pvSetImage(p,iRight, "1rightarrow.png");
  return 0;
}

static int slotTextEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotSliderEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  if(id == sliderZoom)
  {
    float zoom = ((float) val) / 100.0f;
    d->svgAnimator.setScale(zoom);
    d->svgAnimator.setMainObjectMatrix();
    drawSVG1(p,centerWidget,d);
  }
  return 0;
}

static int slotCheckboxEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotRadioButtonEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotGlInitializeEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotGlPaintEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotGlResizeEvent(PARAM *p, int id, DATA *d, int width, int height)
{
  if(p == NULL || id == 0 || d == NULL || width < 0 || height < 0) return -1;
  d->svgAnimator.setWindowSize(width,height);
  drawSVG1(p,centerWidget,d);
  return 0;
}

static int slotGlIdleEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotTabEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotTableTextEvent(PARAM *p, int id, DATA *d, int x, int y, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000 || text == NULL) return -1;
  return 0;
}

static int slotTableClickedEvent(PARAM *p, int id, DATA *d, int x, int y, int button)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000 || button < 0) return -1;
  return 0;
}

static int slotSelectionEvent(PARAM *p, int id, DATA *d, int val, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000 || text == NULL) return -1;
  return 0;
}

static int slotClipboardEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotRightMouseEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  //pvPopupMenu(p,-1,"Menu1,Menu2,,Menu3");
  return 0;
}

static int slotKeyboardEvent(PARAM *p, int id, DATA *d, int val, int modifier)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000 || modifier < -1000) return -1;
  return 0;
}

static int slotMouseMovedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  if(id == centerWidget) // the SVG
  {
    // drag the SVG with your mouse
    //float x0 = d->svgAnimator.x0() + (((x*d->svgAnimator.windowWidth())  / 100.0f) - d->svgAnimator.mouseX0());
    //float y0 = d->svgAnimator.y0() + (((y*d->svgAnimator.windowHeight()) / 100.0f) - d->svgAnimator.mouseY0());
    //d->svgAnimator.setXY0(x0,y0);
    //d->svgAnimator.setMouseXY0(x,y);
    //d->svgAnimator.setMainObjectMatrix();
    //drawSVG1(p,centerWidget,d);
    d->svgAnimator.moveMainObject(x,y);
    drawSVG1(p,centerWidget,d);
    d->svgAnimator.setMouseXY0(x,y);
  }
  return 0;
}

static int slotMousePressedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  if(id == centerWidget) // the SVG
  {
    // remember initial position for dragging
    d->svgAnimator.setMouseXY0(x,y);
  }
  return 0;
}

static int slotMouseReleasedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  if(id == centerWidget) // the SVG
  {
    // drag the SVG with your mouse
    d->svgAnimator.moveMainObject(x,y);
    drawSVG1(p,centerWidget,d);
  }
  return 0;
}

static int slotMouseOverEvent(PARAM *p, int id, DATA *d, int enter)
{
  if(p == NULL || id == 0 || d == NULL || enter < -1000) return -1;
  return 0;
}

static int slotUserEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}
