#ifndef HOMOGRAPHY_H
#define HOMOGRAPHY_H

#include <QObject>
#include <QPointF>
#include <QSizeF>
#include <QMatrix4x4>

class Homography : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPointF p1 MEMBER m_p1 NOTIFY p1Changed)
    Q_PROPERTY(QPointF p2 MEMBER m_p2 NOTIFY p2Changed)
    Q_PROPERTY(QPointF p3 MEMBER m_p3 NOTIFY p3Changed)
    Q_PROPERTY(QPointF p4 MEMBER m_p4 NOTIFY p4Changed)
    Q_PROPERTY(QSizeF sourceSize MEMBER m_sourceSize NOTIFY sourceSizeChanged)
    Q_PROPERTY(QMatrix4x4 matrix READ matrix NOTIFY matrixChanged)

public:
    explicit Homography(QObject *parent = 0);
    QMatrix4x4 matrix() const { return m_matrix; }

signals:
    void p1Changed();
    void p2Changed();
    void p3Changed();
    void p4Changed();
    void sourceSizeChanged();
    void matrixChanged();

private:
    void updateMatrix();

    QPointF m_p1, m_p2, m_p3, m_p4;
    QSizeF m_sourceSize;
    QMatrix4x4 m_matrix;
};

#endif // HOMOGRAPHY_H
