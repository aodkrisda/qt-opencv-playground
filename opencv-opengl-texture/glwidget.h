/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QImage>
#include "opencv2/opencv.hpp"
using namespace cv;

class QtLogo;
class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();
    QTimer *timer;

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void rotateBy();
    void zoom(float z);
    void changeFilter(int index);
    void changeXSpeed(float value);
    void changeYSpeed(float value);
    VideoCapture cap;
    Mat frame;

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void updateFrame();

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
protected:
    bool LoadGLTextures();
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    GLuint matToTexture(cv::Mat &mat, GLenum minFilter, GLenum magFilter, GLenum wrapFilter);

private:
    QtLogo *logo;
    float xrot;                         	// X Rotation
    float yrot;                         	// Y Rotation
    float zrot;                         	// Z Rotation
    float xspeed;				// X Rotation Speed
    float yspeed;				// Y Rotation Speed
    float z;                                    // Depth Into The Screen
    float LightAmbient[];
    float LightDiffuse[];
    float LightPosition[];
    int filter;                                 // Which Filter To Use
    GLuint texture[3];                          // Storage For 3 Textures

    QPoint lastPos;
    QColor qtGreen;
    QColor qtPurple;
};

#endif
