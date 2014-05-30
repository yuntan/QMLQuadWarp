#include "homography.h"
#include <QPoint>
#include <QSize>
#include <QMatrix4x4>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <algorithm>

Homography::Homography(QObject *parent) :
    QObject(parent),
    m_sourceSize(0, 0),
    m_matrix(1, 0, 0, 0,
             0, 1, 0, 0,
             0, 0, 1, 0,
             0, 0, 0, 1)
{
    connect(this, &Homography::p1Changed, &Homography::updateMatrix);
    connect(this, &Homography::p2Changed, &Homography::updateMatrix);
    connect(this, &Homography::p3Changed, &Homography::updateMatrix);
    connect(this, &Homography::p4Changed, &Homography::updateMatrix);
    connect(this, &Homography::sourceSizeChanged, &Homography::updateMatrix);
}

void Homography::updateMatrix() {
    Eigen::Matrix<float, 8, 8> matA;
    Eigen::Matrix<float, 8, 1> vecP;
    Eigen::Matrix<float, 8, 1> vecH;

    int x1 = m_sourceSize.width(), y1 = 0,
        x2 = 0, y2 = 0,
        x3 = 0, y3 = m_sourceSize.height(),
        x4 = m_sourceSize.width(), y4 = m_sourceSize.height();

    // make (X2, Y2) coordinate origin
    int X1 = m_p1.x() - m_p2.x(), Y1 = m_p1.y() - m_p2.y(),
        X2 = 0,                   Y2 = 0,
        X3 = m_p3.x() - m_p2.x(), Y3 = m_p3.y() - m_p2.y(),
        X4 = m_p4.x() - m_p2.x(), Y4 = m_p4.y() - m_p2.y();

    matA << x1, y1, 1, 0, 0, 0, -x1*X1, -y1*X1,
            0, 0, 0, x1, y1, 1, -x1*Y1, -y1*Y1,
            x2, y2, 2, 0, 0, 0, -x2*X2, -y2*X2,
            0, 0, 0, x2, y2, 2, -x2*Y2, -y2*Y2,
            x3, y3, 3, 0, 0, 0, -x3*X3, -y3*X3,
            0, 0, 0, x3, y3, 3, -x3*Y3, -y3*Y3,
            x4, y4, 4, 0, 0, 0, -x4*X4, -y4*X4,
            0, 0, 0, x4, y4, 4, -x4*Y4, -y4*Y4;
//    std::cout << "A:\n" <<  matA << std::endl;

    vecP << X1, Y1, X2, Y2, X3, Y3, X4, Y4;
//    std::cout << "P:\n" << vecP << std::endl;

    // Solve p = Ah
    vecH = matA.colPivHouseholderQr().solve(vecP);
//    std::cout << "H:\n" << vecH << std::endl;

    Eigen::Matrix<float, 3, 3> matH;
    Eigen::Matrix<float, 3, 3> matT;
    Eigen::Matrix<float, 3, 3> res;

    // translate the quadrilateral parallel to the x-y plane
    matH << vecH(0), vecH(1), vecH(2),
            vecH(3), vecH(4), vecH(5),
            vecH(6), vecH(7),       1;
    matT << 1, 0, m_p2.x(),
            0, 1, m_p2.y(),
            0, 0,        1;
    res = matT * matH;

    m_matrix(0, 0) = res(0, 0); m_matrix(0, 1) = res(0, 1); m_matrix(0, 2) = 0; m_matrix(0, 3) = res(0, 2);
    m_matrix(1, 0) = res(1, 0); m_matrix(1, 1) = res(1, 1); m_matrix(1, 2) = 0; m_matrix(1, 3) = res(1, 2);
    m_matrix(2, 0) = 0;         m_matrix(2, 1) = 0;         m_matrix(2, 2) = 1; m_matrix(2, 3) = 0;
    m_matrix(3, 0) = res(2, 0); m_matrix(3, 1) = res(2, 1); m_matrix(3, 2) = 0; m_matrix(3, 3) = res(2, 2);
//    qDebug() << "m_matrix:\n" << m_matrix;

    emit matrixChanged();
}
