//
// Qt binding class for pv functions
// begin: 03-mar-2011
//
#ifndef QT_PV_BINDING_H
#define QT_PV_BINDING_H

#include "processviewserver.h"
#include <qstring.h>

class PV
{
  public:
    PV() { p = NULL; }
    ~PV() {}
    void setParam(PARAM *p_in) { p = p_in; } // you must call this method first
                                             // in order to initialize PARAM *p

    // pv functions
    int lock();
    int unlock();
    int system(const QString &command);
    int SendVersion();
    int XYAllocate(int n);
    int SetXY(int i, float x, float y);
    int InitInternal();
    int Init(int ac, char **av);
    int Accept();
    int CreateThread(int s);
    int GetInitialMask();
    int SetCleanup(int (*cleanup)(void *), void *app_data);
    int PollEvent(char *event);
    int Wait(const QString &pattern);
    int GlUpdate(int id);
    int Sleep(int milliseconds);
    int Warning(const QString &text);
    int MainFatal(const QString &text);
    int ThreadFatal(const QString &text);
    int ScreenHint(int w, int h);
    int SetMouseShape(int shape);
    int SetWhatsThis(int id, const QString &text);
    int WhatsThisPrintf(int id, const QString &format, ...);
    int ClientCommand(const QString &command, const QString &filename);
    int StartDefinition(int num_objects);
    int QLayoutVbox(int id, int parent);
    int QLayoutHbox(int id, int parent);
    int QLayoutGrid(int id, int parent);
    int QWidget(int id, int parent);
    int QLabel(int id, int parent);
    int QComboBox(int id, int parent, int editable, int policy);
    int QLineEdit(int id, int parent);
    int QPushButton(int id, int parent);
    int QLCDNumber(int id, int parent, int numDigits, int segmentStyle, int mode);
    int QSlider(int id, int parent, int minValue, int maxValue, int pageStep, int value, int orientation);
    int QButtonGroup(int id, int parent, int columns, int orientation, const QString &title);
    int QRadioButton(int id, int parent);
    int QCheckBox(int id, int parent);
    int QFrame(int id, int parent, int shape, int shadow, int line_width, int margin);
    int QDraw(int id, int parent);
    int QImage(int id, int parent, const QString &imagename, int *w=NULL, int *h=NULL, int *depth=NULL);
    int QGL(int id, int parent);
    int QTabWidget(int id, int parent);
    int QToolBox(int id, int parent);
    int QGroupBox(int id, int parent, int columns, int orientation, const QString &title);
    int QListBox(int id, int parent);
    int QTable(int id, int parent, int rows, int columns);
    int QSpinBox(int id, int parent, int min, int max, int step);
    int QDial(int id, int parent, int min, int max, int page_step, int value);
    int QProgressBar(int id, int parent, int total_steps, int orientation = Horizontal);
    int QMultiLineEdit(int id, int parent, int editable, int max_lines);
    int QTextBrowser(int id, int parent);
    int QListView(int id, int parent);
    int QIconView(int id, int parent);
    int QVtkTclWidget(int id, int parent);
    int QwtPlotWidget(int id, int parent, int nCurves, int nMarker);
    int QwtScale(int id, int parent, int pos);
    int QwtThermo(int id, int parent);
    int QwtKnob(int id, int parent);
    int QwtCounter(int id, int parent);
    int QwtWheel(int id, int parent);
    int QwtSlider(int id, int parent);
    int QwtDial(int id, int parent);
    int QwtCompass(int id, int parent);
    int QwtAnalogClock(int id, int parent);
    int QDateEdit(int id, int parent);
    int QTimeEdit(int id, int parent);
    int QDateTimeEdit(int id, int parent);
    int EndDefinition();
    int AddWidgetOrLayout(int id, int item, int row, int col);
    int AddStretch(int id, int param);
    int TabOrder(int id1, int id2);
    int DeleteWidget(int id);
    int SetCaption(const QString &text);
    int PlaySound(const QString &filename);
    int Beep();
    int StatusMessage(int r, int g, int b, const QString &format, ...);
    int ToolTip(int id, const QString &text);
    int SetText(int id, const QString &text);
    int Printf(int id, const QString &format, ...);
    int SetValue(int id, int value);
    int Clear(int id);
    int ChangeItem(int id, int index, const QString &bmp_file, const QString &text, int download_icon=1);
    int InsertItem(int id, int index, const QString &bmp_file, const QString &text, int download_icon=1);
    int RemoveItem(int id, int index);
    int RemoveItemByName(int id, const QString &name);
    int AddColumn(int id, const QString &text, int size);
    int SetTableText(int id, int x, int y, const QString &text);
    int SetTableButton(int id, int x, int y, const QString &text);
    int SetTableCheckBox(int id, int x, int y, int state, const QString &text);
    int SetTableComboBox(int id, int x, int y, int editable, const QString &textlist);
    int SetTableLabel(int id, int x, int y, const QString &text);
    int TablePrintf(int id, int x, int y, const QString &format, ...);
    int SetTableTextAlignment(int id, int x, int y, int alignment);
    int Mysqldump(int id, const QString &command);
    int CSVdump(int id, const QString &filename, char delimitor='\t');
    int CSVcreate(const QString &command, const QString &filename);
    int CSV(int id, const QString &command, char delimitor='\t');
    int SetListViewText(int id, const QString &path, int column, const QString &text);
    int ListViewPrintf(int id, const QString &path, int column, const QString &format, ...);
    int ListViewSetSelected(int id, const QString &path, int column, int selected);
    int ListBoxSetSelected(int id, int index, int selected);
    int SetColumnWidth(int id, int column, int width);
    int SetRowHeight(int id, int row, int height);
    int SetWordWrap(int id, int wrap);
    int SetPixmap(int id, const QString &bmp_file, int download_icon=1);
    int SetTablePixmap(int id, int x, int y, const QString &bmp_file, int download_icon=1);
    int SetSource(int id, const QString &html_file);
    int SetImage(int id, const QString &filename);
    int SetBackgroundColor(int id, int r, int g, int b);
    int SetPaletteBackgroundColor(int id, int r, int g, int b);
    int SetPaletteForegroundColor(int id, int r, int g, int b);
    int SetFontColor(int id, int r, int g, int b);
    int SetFont(int id, const QString &family, int pointsize, int bold, int italic , int underline, int strikeout);
    int DisplayNum(int id, int num);
    int DisplayFloat(int id, float val);
    int DisplayStr(int id, const QString &str);
    int AddTab(int id, int id_child, const QString &str);
    int SetListViewPixmap(int id, const QString &path, const QString &bmp_file, int column, int download_icon=1);
    int RemoveListViewItem(int id, const QString &path);
    int RemoveIconViewItem(int id, const QString &text);
    int SetIconViewItem(int id, const QString &bmp_file, const QString &text, int download_icon=1);
    int SetDateOrder(int id, int order);
    int SetDate(int id, int year, int month, int day);
    int SetMinDate(int id, int year, int month, int day);
    int SetMaxDate(int id, int year, int month, int day);
    int SetTime(int id, int hour, int minute, int second=0, int msec=0);
    int SetMinTime(int id, int hour, int minute, int second=0, int msec=0);
    int SetMaxTime(int id, int hour, int minute, int second=0, int msec=0);
    int EnsureCellVisible(int id, int row, int col=1);
    int MoveCursor(int id, int cursor);
    int ScrollToAnchor(int id, const QString &anchor);
    int SetZoomFactor(int id, float factor);
    int Text(int id);
    int RequestGeometry(int id);
    int RequestParentWidgetId(int id);
    int Selection(int id);
    int RequestSvgBoundsOnElement(int id, const QString &objectname);
    int RequestSvgMatrixForElement(int id, const QString &objectname);
    int MoveContent(int id, int pos);
    int SetGeometry(int id, int x, int y, int w, int h);
    int SetMinSize(int id, int w, int h);
    int SetMaxSize(int id, int w, int h);
    int SetAlignment(int id, int alignment);
    int SetChecked(int id, int state);
    int Move(int id, int x, int y);
    int Resize(int id, int w, int h);
    int Hide(int id);
    int Show(int id);
    int SetParent(int id, int id_parent);
    int SetMultiSelection(int id, int mode);
    int SetEchoMode(int id, int mode);
    int SetEditable(int id, int editable);
    int SetEnabled(int id, int enabled);
    int TableSetEnabled(int id, int x, int y, int enabled);
    int TableSetHeaderResizeEnabled(int id, int horizontal ,int enabled, int section);
    int SetSorting(int id, int column, int mode);
    int SetTabPosition(int id, int pos);
    int SetNumRows(int id, int num);
    int SetNumCols(int id, int num);
    int InsertRows(int id, int row, int count=1);
    int InsertColumns(int id, int col, int count=1);
    int RemoveRow(int id, int row);
    int RemoveColumn(int id, int col);
    int SetCurrentItem(int id, int index);
    int SetTimeEditDisplay(int id, int hour, int minute, int second, int ampm);
    int ListViewEnsureVisible(int id, const QString &path);
    int ListViewSetOpen(int id, const QString &path, int open);
    int ListViewSetHidden(int id, int column, int hidden);
    int ListViewSetStandardPopupMenu(int id, int standard_menu);
    int SetStyle(int id, int shape, int shadow, int line_width, int margin);
    int SetMovie(int id, int background, const QString &filename);
    int MovieControl(int id, int step);
    int MovieSpeed(int id, int speed);
    int VtkTcl(int id, const QString &tcl_command);
    int VtkTclPrintf(int id, const QString &format, ...);
    int VtkTclScript(int id, const QString &filename);
    int Hyperlink(const QString &link);
    int SendUserEvent(int id, const QString &text);
    int WriteFile(const QString &filename, int width, int height);
    int CloseFile();
    int GetText(const QString &command, QString *text);
    int ParseEvent(const QString &event, int *id, QString *text);
    int CopyToClipboard(int id);
    int Print(int id);
    int Save(int id);
    int Save(int id, const QString &filename);
    int SaveAsBmp(int id, const QString &filename);
    int SendFile(const QString &filename);
    int DownloadFileAs(const QString &filename, const QString &newname);
    int DownloadFile(const QString &filename);
    int ClearMessageQueue();
    int tcpsend(const QString &buf, int len);
    int tcpsend_binary(const QString &buf, int len);
    int tcpreceive( char *buf, int maxlen);
    int tcpreceive_binary( char *buf, int maxlen);
    int GlBegin(int id);
    int SendOpenGL(const QString &filename, GLuint *listarray, int max_array, glFont *proportional=NULL, glFont *fixed=NULL);
    int GlEnd();
    int FileDialog(int id_return, int type);
    int PopupMenu(int id_return, const QString &text);
    int MessageBox(int id_return, int type, const QString &text, int button0, int button1, int button2);
    int InputDialog(int id_return, const QString &text, const QString &default_text);
    int RunModalDialog(int width, int height, int (*showMask)(PARAM *p), void *userData,int (*readData)(void *d), int (*showData)(PARAM *p, void *d), void *d);
    int RunModalDialogScript(int width, int height);
    int TerminateModalDialog();
    int UpdateBaseWindow();
    int UpdateBaseWindowOnOff(int onoff);
    int AddDockWidget(const QString &title, int dock_id, int root_id, int allow_close=0, int floating=1, int allow_left=1, int allow_right=0, int allow_top=0, int allow_bottom=0);
    int DeleteDockWidget(int dock_id, int delete_widget=0);
    int SetZoomX(int id, float zoom);
    int SetZoomY(int id, float zoom);
    int SetSelector(int id, int state);

    // g functions
    int glencode_set_param();
    int getIntegers(const QString &text, IntegerArray *ia);
    int getFloats(const QString &text, FloatArray *fa);
    int gWriteFile(const QString &file);
    int gCloseFile();
    int gBeginDraw(int id);
    int gBox(int x, int y, int w, int h);
    int gRect(int x, int y, int w, int h);
    int gEndDraw();
    int gLineTo(int x, int y);
    int gBufferedLine();
    int gLine( float *x, float *y, int n);
    int gMoveTo(int x, int y);
    int gRightYAxis( float start, float delta, float end, int draw);
    int gSetColor(int r, int g, int b);
    int gSetWidth(int w);
    int gSetStyle(int style);
    int gDrawArc(int x, int y, int w, int h, int start_angle, int angle_length);
    int gDrawPie(int x, int y, int w, int h, int start_angle, int angle_length);
    int gDrawPolygon(int *x, int *y, int n);
    int gSetFont(const QString &family, int size, int weight, int italic);
    int gSetLinestyle(int style);
    int gText(int x, int y, const QString &text, int alignment);
    int gTextInAxis( float x, float y, const QString &text, int alignment);
    int gSetFloatFormat(const QString &text);
    int gXAxis( float start, float delta, float end, int draw);
    int gYAxis( float start, float delta, float end, int draw);
    int gXGrid();
    int gYGrid();
    int gBoxWithText(int x, int y, int w, int h, int fontsize, const QString &xlabel, const QString &ylabel, const QString &rylabel);
    int gComment(const QString &comment);
    int gPlaySVG(const QString &filename);
    int gSocketPlaySVG(const QString &svgstring);
    int gTranslate( float x, float y);
    int gRotate( float angle);
    int gScale( float sx, float sy);
    int getSvgBoundsOnElement(const QString &text, float *x, float *y, float *width, float *height);
    int getSvgMatrixForElement(const QString &text, float *m11, float *m12, float *m21, float *m22, float *det, float *dx,  float *dy);
    int getGeometry(const QString &text, int *x, int *y, int *width, int *height);
    int getParentWidgetId(const QString &text, int *parent);

    // qwt functions
    int qwtScaleSetTitle(int id, const QString &text);
    int qwtScaleSetTitleColor(int id, int r, int g, int b);
    int qwtScaleSetTitleFont(int id, const QString &family, int pointsize, int bold, int italic, int underline, int strikeout);
    int qwtScaleSetTitleAlignment(int id, int flags);
    int qwtScaleSetBorderDist(int id, int start, int end);
    int qwtScaleSetBaselineDist(int id, int bd);
    int qwtScaleSetScaleDiv(int id, float lBound, float hBound, int maxMaj, int maxMin, int log, float step, int ascend);
    int qwtScaleSetLabelFormat(int id, int f, int prec, int fieldWidth);
    int qwtScaleSetLabelAlignment(int id, int align);
    int qwtScaleSetLabelRotation(int id, float rotation);
    int qwtScaleSetPosition(int id, int position);
    int qwtThermoSetScale(int id, float min, float max, float step, int logarithmic);
    int qwtThermoSetOrientation(int id, int orientation, int position);
    int qwtThermoSetBorderWidth(int id, int width);
    int qwtThermoSetFillColor(int id, int r, int g, int b);
    int qwtThermoSetAlarmColor(int id, int r, int g, int b);
    int qwtThermoSetAlarmLevel(int id, float level);
    int qwtThermoSetAlarmEnabled(int id, int tf);
    int qwtThermoSetPipeWidth(int id, int width);
    int qwtThermoSetRange(int id, float vmin, float vmax, float step=0.0f);
    int qwtThermoSetMargin(int id, int margin);
    int qwtThermoSetValue(int id, float value);
    int qwtKnobSetScale(int id, float min, float max, float step, int logarithmic);
    int qwtKnobSetMass(int id, float mass);
    int qwtKnobSetOrientation(int id, int orientation);
    int qwtKnobSetReadOnly(int id, int rdonly);
    int qwtKnobSetKnobWidth(int id, int width);
    int qwtKnobSetTotalAngle(int id, float angle);
    int qwtKnobSetBorderWidth(int id, int width);
    int qwtKnobSetSymbol(int id, int symbol);
    int qwtKnobSetValue(int id, float value);
    int qwtCounterSetStep(int id, float step);
    int qwtCounterSetMinValue(int id, float value);
    int qwtCounterSetMaxValue(int id, float value);
    int qwtCounterSetStepButton1(int id, int n);
    int qwtCounterSetStepButton2(int id, int n);
    int qwtCounterSetStepButton3(int id, int n);
    int qwtCounterSetNumButtons(int id, int n);
    int qwtCounterSetIncSteps(int id, int button, int n);
    int qwtCounterSetValue(int id, float value);
    int qwtWheelSetMass(int id, float mass);
    int qwtWheelSetOrientation(int id, int orientation);
    int qwtWheelSetReadOnly(int id, int rdonly);
    int qwtWheelSetTotalAngle(int id, float angle);
    int qwtWheelSetTickCnt(int id, int cnt);
    int qwtWheelSetViewAngle(int id, float angle);
    int qwtWheelSetInternalBorder(int id, int width);
    int qwtWheelSetWheelWidth(int id, int width);
    int qwtWheelSetValue(int id, float value);
    int qwtSliderSetScale(int id, float min, float max, float step, int logarithmic);
    int qwtSliderSetMass(int id, float mass);
    int qwtSliderSetOrientation(int id, int orientation);
    int qwtSliderSetReadOnly(int id, int rdonly);
    int qwtSliderSetBgStyle(int id, int style);
    int qwtSliderSetScalePos(int id, int pos);
    int qwtSliderSetThumbLength(int id, int length);
    int qwtSliderSetThumbWidth(int id, int width);
    int qwtSliderSetBorderWidth(int id, int width);
    int qwtSliderSetMargins(int id, int x, int y);
    int qwtSliderSetValue(int id, float value);
    int qwtCompassSetSimpleCompassRose(int id, int numThorns, int numThornLevels, float width=0.2f);
    int qwtCompassSetRange(int id, float vmin, float vmax, float step=0.0f);
    int qwtCompassSetMass(int id, float mass);
    int qwtCompassSetReadOnly(int id, int rdonly);
    int qwtCompassSetFrameShadow(int id, int shadow);
    int qwtCompassShowBackground(int id, int show);
    int qwtCompassSetLineWidth(int id, int width);
    int qwtCompassSetMode(int id, int mode);
    int qwtCompassSetWrapping(int id, int wrap);
    int qwtCompassSetScale(int id, int maxMajIntv, int maxMinIntv, float step);
    int qwtCompassSetScaleArc(int id, float min, float max);
    int qwtCompassSetOrigin(int id, float o);
    int qwtCompassSetNeedle(int id, int which, int r1=0, int g1=0, int b1=0, int r2=255, int g2=255, int b2=255, int r3=128, int g3=128, int b3=128);
    int qwtCompassSetValue(int id, float value);
    int qwtDialSetRange(int id, float vmin, float vmax, float step=0.0f);
    int qwtDialSetMass(int id, float mass);
    int qwtDialSetReadOnly(int id, int rdonly);
    int qwtDialSetFrameShadow(int id, int shadow);
    int qwtDialShowBackground(int id, int show);
    int qwtDialSetLineWidth(int id, int width);
    int qwtDialSetMode(int id, int mode);
    int qwtDialSetWrapping(int id, int wrap);
    int qwtDialSetScale(int id, int maxMajIntv, int maxMinIntv, float step);
    int qwtDialSetScaleArc(int id, float min, float max);
    int qwtDialSetOrigin(int id, float o);
    int qwtDialSetNeedle(int id, int which, int r1=0, int g1=0, int b1=0, int r2=255, int g2=255, int b2=255, int r3=128, int g3=128, int b3=128);
    int qwtDialSetValue(int id, float value);
    int qwtAnalogClockSetTime(int id, int hour, int minute, int second);
    int qwtAnalogClockSetMass(int id, float mass);
    int qwtAnalogClockSetReadOnly(int id, int rdonly);
    int qwtAnalogClockSetFrameShadow(int id, int shadow);
    int qwtAnalogClockShowBackground(int id, int show);
    int qwtAnalogClockSetLineWidth(int id, int width);
    int qwtAnalogClockSetMode(int id, int mode);
    int qwtAnalogClockSetWrapping(int id, int wrap);
    int qwtAnalogClockSetScale(int id, int maxMajIntv, int maxMinIntv, float step);
    int qwtAnalogClockSetScaleArc(int id, float min, float max);
    int qwtAnalogClockSetOrigin(int id, float o);
    int qwtAnalogClockSetNeedle(int id, int which, int r1=0, int g1=0, int b1=0, int r2=255, int g2=255, int b2=255, int r3=128, int g3=128, int b3=128);
    int qwtAnalogClockSetValue(int id, float value);

    // qpw functions
    int qpwSetCurveData(int id, int c, int count, double *x, double *y);
    int qpwSetBufferedCurveData(int id, int c);
    int qpwReplot(int id);
    int qpwSetTitle(int id, const QString &text);
    int qpwSetCanvasBackground(int id, int r, int g, int b);
    int qpwEnableOutline(int id, int val);
    int qpwSetOutlinePen(int id, int r, int g, int b);
    int qpwSetAutoLegend(int id, int val);
    int qpwEnableLegend(int id, int val);
    int qpwSetLegendPos(int id, int pos);
    int qpwSetLegendFrameStyle(int id, int style);
    int qpwEnableGridXMin(int id);
    int qpwSetGridMajPen(int id, int r, int g, int b, int style);
    int qpwSetGridMinPen(int id, int r, int g, int b, int style);
    int qpwEnableAxis(int id, int pos);
    int qpwSetAxisTitle(int id, int pos, const QString &text);
    int qpwSetAxisOptions(int id, int pos, int val);
    int qpwSetAxisMaxMajor(int id, int pos, int val);
    int qpwSetAxisMaxMinor(int id, int pos, int val);
    int qpwInsertCurve(int id, int index, const QString &text);
    int qpwRemoveCurve(int id, int index);
    int qpwSetCurvePen(int id, int index, int r, int g, int b, int width=1, int style=SolidLine);
    int qpwSetCurveSymbol(int id, int index, int symbol, int r1, int g1, int b1, int r2, int g2, int b2, int w, int h);
    int qpwSetCurveYAxis(int id, int index, int pos);
    int qpwInsertMarker(int id, int index);
    int qpwSetMarkerLineStyle(int id, int index, int style);
    int qpwSetMarkerPos(int id, int index, float x, float y);
    int qpwSetMarkerLabelAlign(int id, int index, int align);
    int qpwSetMarkerPen(int id, int index, int r, int g, int b, int style);
    int qpwSetMarkerLabel(int id, int number, const QString &text);
    int qpwSetMarkerFont(int id, int index, const QString &family, int size, int style);
    int qpwSetMarkerSymbol(int id, int index, int symbol, int r1, int g1, int b1, int r2, int g2, int b2, int w, int h);
    int qpwInsertLineMarker(int id, int index, const QString &text, int pos);
    int qpwSetAxisScaleDraw(int id, int pos, const QString &text );
    int qpwSetAxisScale(int id, int pos, float min, float max, float step);

    // param structure
    PARAM *p;
};

#endif
