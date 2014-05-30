uniform highp mat4 qt_Matrix;
attribute highp vec4 qt_Vertex;
attribute highp vec2 qt_MultiTexCoord0;
varying highp vec2 qt_TexCoord0;

uniform highp float w;
uniform highp float h;
uniform highp mat4 homography;

void main() {
    qt_TexCoord0 = qt_MultiTexCoord0;

    highp mat4 scale = mat4(w,0,0,0, 0,h,0,0, 0,0,1,0, 0,0,0,1);
    gl_Position = qt_Matrix * homography * scale * qt_Vertex;
}
