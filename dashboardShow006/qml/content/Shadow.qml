import QtQuick 2.0

ShaderEffect {
    id: shader
    width: 400
    height: 400

    property real angle: 0.0
    property real startAngle: 0.0
    property bool direction: false
    property color ringColor: "white"
    property real lineWidth: 0.0
    property real ringRadius: 0.0
    property real gradient: 0.0
    property real viewport_width: width
    property real viewport_height: height
//    property real opacity: 1

    fragmentShader: "

#ifdef GL_ES
precision mediump float;
#endif

#define PI  3.14159265359
#define TPI 6.28318530718
#define HPI 1.57079632679


uniform float x;
uniform float y;
uniform float opacity;
uniform float viewport_width;
uniform float viewport_height;
uniform float angle;
uniform float startAngle;
uniform bool direction;
uniform float gradient;
uniform vec4 ringColor;
varying highp vec2 qt_TexCoord0;

uniform float lineWidth;
uniform float ringRadius;

vec3 iResolution = vec3(viewport_width, viewport_height, 0.0);

//float rnd(float s) { return mod(10E6*sin(s*2526.2352+6532.235),1.0); }

void main()
{
    vec2 pos = (ringRadius + 0.12)*2.0*(gl_FragCoord.xy / iResolution.y - vec2(0.48 + 0.48 * x / 200.0,0.5 - 0.5 * y / 100.0));
    float ang = 0.0;
    float v = 0.0;
    if(angle > startAngle) {
        ang = mod((1.0-startAngle/360.0)-atan(pos.y,pos.x)/TPI,1.0);
        v = mod((angle - startAngle)/360.0,1.0);
    }
    else if(angle < startAngle) {
        ang = mod((1.0-(360.0 - startAngle)/360.0)+atan(pos.y,pos.x)/TPI,1.0);
        v = mod(((startAngle - angle))/360.0,1.0);
    }


    float radius = length(pos);

    float MA = 0.5/iResolution.y; // 圆环最前面抗锯齿参数，数字越大，边缘模糊化越大
    float MR = 32.0/iResolution.y; // 抗锯齿参数，数字越大，锯齿越小，边缘模糊化越大
    float AI = (0.5+sin(TPI/100.0))/gradient; // 颜色梯度变化程度

    float I = smoothstep(0.0,1.0, ang/v/*/AI*/);

    float drawRing = smoothstep(-MA,MA,v-ang);
    float tint = smoothstep(-MR,MR,1.0-abs(radius-ringRadius)/lineWidth*1000.0);

    vec4 col = ringColor*drawRing*I*tint*opacity;

    gl_FragColor = vec4(col/*,0.0*/);

// your main function body code range below
}
"

}
