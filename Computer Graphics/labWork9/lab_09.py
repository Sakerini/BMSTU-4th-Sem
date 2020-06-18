from PyQt5 import QtWidgets, uic
from PyQt5.QtWidgets import QMessageBox, QApplication, QTableWidgetItem
from PyQt5.QtGui import QPen, QColor, QImage
from PyQt5.QtCore import Qt, QPoint
import copy


class Window(QtWidgets.QMainWindow):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)
        uic.loadUi("mainwindow.ui", self)

        self.scene = myScene(0, 0, 750, 750)
        self.scene.win = self
        self.mainview.setScene(self.scene)

        self.image = QImage(750, 750, QImage.Format_ARGB32_Premultiplied)

        self.figure_color = QColor(Qt.red)
        self.clip_color = QColor(Qt.blue)
        self.clipper_color = QColor(Qt.black)

        self.image.fill(Qt.white)
        self.radio_clipper.setChecked(True)

        self.clear_all_btn.clicked.connect(lambda: cleanAll(self))

        self.line_color_btn.clicked.connect(lambda: get_figure_color(self))
        self.clip_color_btn.clicked.connect(lambda: get_clip_color(self))
        self.clipper_color_btn.clicked.connect(lambda: get_clipper_color(self))
        self.add_point_btn.clicked.connect(lambda: add_point_by_btn(self))
        self.clip_all_btn.clicked.connect(lambda: lineClipping(self))

        self.clip_now = None
        self.clip_lock = None
        self.clipper = []
        self.isClipper = False

        self.fig_now = None
        self.fig_lock = None
        self.figure = []
        self.isFigure = False

        s = QtWidgets.QGraphicsScene(0, 0, 10, 10)
        s.setBackgroundBrush(Qt.red)
        self.graphicsView_4.setScene(s)

        s = QtWidgets.QGraphicsScene(0, 0, 10, 10)
        s.setBackgroundBrush(Qt.blue)
        self.graphicsView_5.setScene(s)

        s = QtWidgets.QGraphicsScene(0, 0, 10, 10)
        s.setBackgroundBrush(Qt.black)
        self.graphicsView_6.setScene(s)


class myScene(QtWidgets.QGraphicsScene):
    def mousePressEvent(self, event):
        global w
        if w.radio_figure.isChecked():
            if event.button() == Qt.RightButton:
                lock_figure(w)
            if not w.isFigure:
                verthoriz = False
                modifiers = QApplication.keyboardModifiers()
                if modifiers == Qt.ControlModifier:
                    verthoriz = True
                addPoint(event.scenePos(), verthoriz)
        elif w.radio_clipper.isChecked():
            if event.button() == Qt.RightButton:
                lock_clipper(w)
            if not w.isClipper:
                verthoriz = False
                modifiers = QApplication.keyboardModifiers()
                if modifiers == Qt.ControlModifier:
                    verthoriz = True
                addClipper(event.scenePos(), verthoriz)


def add_row(win):
    win.table.insertRow(win.table.rowCount())


def add_point_by_btn(win):
    x = win.x_point.text()
    y = win.y_point.text()
    if is_int(x) and is_int(y):
        x = int(x)
        y = int(y)
    else:
        msg = QMessageBox()
        msg.setText("Ошибка!")
        msg.setInformativeText("Координатами могут быть только целые числа!")
        msg.setWindowTitle("Ошибка ввода!")
        msg.exec_()
        return
    p = QPoint()
    p.setX(x)
    p.setY(y)
    if w.radio_figure.isChecked():
        print('p')
        addPoint(p, False)
    elif w.radio_clipper.isChecked():
        addClipper(p, False)

        
def sign(x):
    if not x:
        return 0
    else:
        return x / abs(x)


def is_int(num):
    try:
        val = int(num)
        return 1
    except:
        return 0


def lock_clipper(win):
    win.scene.addLine(win.clip_now.x(), win.clip_now.y(), win.clip_lock.x(), win.clip_lock.y(), w.clipper_color)
    win.clip_now = None
    win.clip_lock = None
    win.isClipper = True


def lock_figure(win):
    win.scene.addLine(win.fig_now.x(), win.fig_now.y(), win.fig_lock.x(), win.fig_lock.y(), w.figure_color)
    win.fig_now = None
    win.fig_lock = None
    win.isFigure = True


def get_figure_color(win):
    color = QtWidgets.QColorDialog.getColor(initial=Qt.white, title='Цвет границ',
                                            options=QtWidgets.QColorDialog.DontUseNativeDialog)
    if color.isValid():
        win.figure_color = color
        s = QtWidgets.QGraphicsScene(0, 0, 10, 10)
        s.setBackgroundBrush(color)
        win.graphicsView_4.setScene(s)


def get_clip_color(win):
    color = QtWidgets.QColorDialog.getColor(initial=Qt.white, title='Цвет границ',
                                            options=QtWidgets.QColorDialog.DontUseNativeDialog)
    if color.isValid():
        win.clip_color = color
        s = QtWidgets.QGraphicsScene(0, 0, 10, 10)
        s.setBackgroundBrush(color)
        win.graphicsView_5.setScene(s)


def get_clipper_color(win):
    color = QtWidgets.QColorDialog.getColor(initial=Qt.white, title='Цвет границ',
                                            options=QtWidgets.QColorDialog.DontUseNativeDialog)
    if color.isValid():
        win.clipper_color = color
        s = QtWidgets.QGraphicsScene(0, 0, 10, 10)
        s.setBackgroundBrush(color)
        win.graphicsView_6.setScene(s)


def addClipper(point, verthoriz=False):
    global w
    x = point.x()
    y = point.y()
    if w.clip_now is None:
        w.clip_now = point
        w.clipper.append([w.clip_now.x(), w.clip_now.y()])
        add_row(w)
        i = w.table.rowCount() - 1
        item_x = QTableWidgetItem("{0}".format(x))
        item_y = QTableWidgetItem("{0}".format(y))
        w.table.setItem(i, 0, item_x)
        w.table.setItem(i, 1, item_y)
        w.clip_lock = point
    else:
        if verthoriz:
            if abs(w.clip_now.x() - point.x()) >= abs(w.clip_now.y() - point.y()):
                y = w.clip_now.y()
            else:
                x = w.clip_now.x()
        point = QPoint(x, y)
        w.clipper.append([x, y])
        add_row(w)
        i = w.table.rowCount() - 1
        item_x = QTableWidgetItem("{0}".format(x))
        item_y = QTableWidgetItem("{0}".format(y))
        w.table.setItem(i, 0, item_x)
        w.table.setItem(i, 1, item_y)
        w.scene.addLine(x, y, w.clip_now.x(), w.clip_now.y(), w.clipper_color)
        w.clip_now = point


def addPoint(point, verthoriz=False):
    global w
    x = point.x()
    y = point.y()
    if w.fig_now is None:
        w.fig_now = point
        w.figure.append([w.fig_now.x(), w.fig_now.y()])
        w.fig_lock = point
    else:
        if verthoriz:
            if abs(w.fig_now.x() - point.x()) >= abs(w.fig_now.y() - point.y()):
                y = w.fig_now.y()
            else:
                x = w.fig_now.x()
        point = QPoint(x, y)
        w.figure.append([x, y])
        w.scene.addLine(x, y, w.fig_now.x(), w.fig_now.y(), w.figure_color)
        w.fig_now = point


def cleanAll(win):
    win.scene.clear()
    win.clip_now = None
    win.clip_lock = None
    win.clipper = []
    win.isClipper = False

    win.fig_now = None
    win.fig_lock = None
    win.figure = []
    win.isFigure = False

    r = win.table.rowCount()
    for i in range(r, -1, -1):
        win.table.removeRow(i)

def vectP(v0, v1, v2):
    x1 = v1[0] - v0[0]
    y1 = v1[1] - v0[1]

    x2 = v2[0] - v1[0]
    y2 = v2[1] - v1[1]

    r = x1 * y2 - x2 * y1
    return r


def isConvex(edges):
    # 1. Находим знаки
    signs = []

    for i in range(1, len(edges) - 1):
        vo = edges[i - 1]  # iая вершина
        vi = edges[i]  # i+1 вершина
        vn = edges[i + 1]  # i+2 вершина и все остальные

        r = vectP(vo, vi, vn)  # векторное произведение векторов (i, i+1) и (i, i+2)
        signs.append(sign(r))  # знак

    vo = edges[len(edges) - 1]  # iая вершина
    vi = edges[0]  # i+1 вершина
    vn = edges[1]  # i+2 вершина и все остальные

    r = vectP(vo, vi, vn)  # векторное произведение векторов (i, i+1) и (i, i+2)
    signs.append(sign(r))  # знак

    # 2. Проверяем знаки

    return checkSigns(signs)

def checkSigns(signs: list):
    '''Returns 0 if its convex else 1 if signs are positive(clockwise) or -1 if they are neg'''
    print(signs)
    # counters
    zeros = 0
    positive = 0 
    negative = 0
    
    for i in range(len(signs)):
        curr = signs[i]

        if curr >= 0:
            positive += 1
        if curr <= 0:
            negative += 1
        if curr == 0:
            zeros += 1
    print("positives {}".format(positive))
    print("zeros {}".format(zeros))

    if zeros == len(signs):
        return 0
    if positive == (len(signs)):
        return 1
    if negative == (len(signs)):
        return -1
    return 0

def lineClipping(win):
    if not win.isClipper:
        msg = QMessageBox()
        msg.setText("Ошибка!")
        msg.setInformativeText("Отсекатель не задан!")
        msg.setWindowTitle("Ошибка ввода!")
        msg.exec_()
        return
    if not win.isFigure:
        msg = QMessageBox()
        msg.setText("Ошибка!")
        msg.setInformativeText("Многоугольник не задан!")
        msg.setWindowTitle("Ошибка ввода!")
        msg.exec_()
        return
    clockwise = isConvex(win.clipper)
    if clockwise == 0:
        msg = QMessageBox()
        msg.setText("Ошибка!")
        msg.setInformativeText("Отсекатель вогнутый!")
        msg.setWindowTitle("Ошибка ввода!")
        msg.exec_()
        return
    p = sutherland_hodgman(win.clipper, win.figure, clockwise)
    if p:
        p.append(p[0])
        for i in range(len(p) - 1):
            win.scene.addLine(p[i][0], p[i][1], p[i + 1][0], p[i + 1][1], QPen(win.clip_color, 2))


def is_visible(point, peak1, peak2, clockwise):
    v = vectP(point, peak2, peak1)
    if clockwise * v <= 0:
        return True
    else:
        return False


def is_intersection(ed1, ed2, norm):
    vis1 = is_visible(ed1[0], ed2[0], ed2[1], norm)
    vis2 = is_visible(ed1[1], ed2[0], ed2[1], norm)
    if (vis1 and not vis2) or (not vis1 and vis2):
        p1 = ed1[0]
        p2 = ed1[1]

        q1 = ed2[0]
        q2 = ed2[1]
        delta = (p2[0] - p1[0]) * (q1[1] - q2[1]) - (q1[0] - q2[0]) * (p2[1] - p1[1])
        delta_t = (q1[0] - p1[0]) * (q1[1] - q2[1]) - (q1[0] - q2[0]) * (q1[1] - p1[1])

        if abs(delta) <= 1e-6:
            return p2

        t = delta_t / delta

        I = []
        I.append(ed1[0][0] + (ed1[1][0] - ed1[0][0]) * t)
        I.append(ed1[0][1] + (ed1[1][1] - ed1[0][1]) * t)
        return I
    else:
        return False


def sutherland_hodgman(clipper, polygon, clockwise):
    clipper.append(clipper[0])

    s = None
    f = None
    # цикл по вершинам отсекателя - 1
    for i in range(len(clipper) - 1):
        new = []
        for j in range(len(polygon)):  # цикл по вершинам многоугольника
            if j == 0:
                f = polygon[j]
            else:
                t = is_intersection([s, polygon[j]], [clipper[i], clipper[i + 1]], clockwise)  # пересечение s, p[j] и c[i], c[i+1]
                if t:  # если есть
                    new.append(t)

            s = polygon[j]
            if is_visible(s, clipper[i], clipper[i + 1], clockwise):  # видимость вершины многоугольника относительно ребра отсекателя
                new.append(s)

        if len(new) != 0:
            t = is_intersection([s, f], [clipper[i], clipper[i + 1]], clockwise)  # точка пересечения s, f и c[i], c[i+1]
            if t:
                new.append(t)

        polygon = copy.deepcopy(new)  # новый многоугольник

    if len(polygon) == 0:
        return False
    else:
        return polygon


if __name__ == "__main__":
    import sys

    app = QtWidgets.QApplication(sys.argv)
    w = Window()
    w.show()
    sys.exit(app.exec_())
