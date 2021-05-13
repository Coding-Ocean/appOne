#include"libOne.h"
void gmain() {
    window(1000, 1000);
    const int numCorners = 32;
    const int numVertices = numCorners * 4;
    const int numTriangles = numCorners * 2 + (numCorners - 2) * 2;
    const int numIndices = numTriangles * 3;
    VECTOR3 p[numVertices];
    VECTOR3 n[numVertices];
    VECTOR3 _p[numVertices];
    VECTOR3 _n[numVertices];
    float divRad = 3.141592f * 2 / numCorners;
    for (int i = 0; i < numCorners; i++) {
        float rad = divRad * i;
        float x = cos(rad);
        float y = -sin(rad);
        //側面上
        p[i] = VECTOR3(x, 1, y);
        n[i] = VECTOR3(x, 0, y);
        //側面下
        p[i + numCorners] = VECTOR3(x, -1, y);
        n[i + numCorners] = VECTOR3(x, 0, y);
        //上面
        p[i + numCorners * 2] = VECTOR3(x, 1, y);
        n[i + numCorners * 2] = VECTOR3(0, 1, 0);
        //底面
        p[i + numCorners * 3] = VECTOR3(x, -1, y);
        n[i + numCorners * 3] = VECTOR3(0, -1, 0);
    }

    int indices[numIndices];
    //側面インデックス
    int j = 0;
    for (int i = 0; i < numCorners; i++) {
        indices[j++] = i;
        indices[j++] = i + numCorners;
        indices[j++] = i + 1;
        indices[j++] = i + 1;
        indices[j++] = i + numCorners;
        indices[j++] = i + numCorners + 1;
    }
    indices[j - 4] = 0;
    indices[j - 3] = 0;
    indices[j - 1] = numCorners;
    //上面インデックス
    for (int i = 0; i < numCorners - 2; i++) {
        indices[j++] = numCorners * 2;
        indices[j++] = numCorners * 2 + i + 1;
        indices[j++] = numCorners * 2 + i + 2;
    }
    //底面インデックス
    for (int i = 0; i < numCorners - 2; i++) {
        indices[j++] = numCorners * 3;
        indices[j++] = numCorners * 3 + i + 2;
        indices[j++] = numCorners * 3 + i + 1;
    }

    COLOR c(255, 128, 255);
    COLOR _c[numVertices];
    float angle = 0;
    float pz = 0;
    VECTOR3 l(0, 0, 1);
    angleMode(RADIANS);
    while (notQuit) {
        MATRIX m, m2;
        m.mulTranslate(0, 0, -5);
        m.mulRotateY(angle * 2);
        m.mulRotateX(angle);
        m2 = m;
        m2._14 = 0;
        m2._24 = 0;
        m2._34 = 0;
        for (int i = 0; i < numVertices; i++) {
            _p[i] = m * p[i];
            _n[i] = m2 * n[i];
            _c[i] = c * max(0, dot(_n[i], l));

            _p[i].x /= -_p[i].z;
            _p[i].y /= -_p[i].z;
            _p[i].z = 1;
        }
        angle += 0.01f;
        clear(60, 120, 240);
        for (int i = 0; i < numTriangles; i++) {

            int j = indices[i * 3];
            int k = indices[i * 3 + 1];
            int l = indices[i * 3 + 2];
            //k,l,mが作る三角形が表かどうか判定する
            float ax = _p[k].x - _p[j].x;
            float ay = _p[k].y - _p[j].y;
            float bx = _p[l].x - _p[j].x;
            float by = _p[l].y - _p[j].y;
            if (ax * by - ay * bx > 0) { //表だったら
                triangle(_p[j], _p[k], _p[l], _c[j], _c[k], _c[l]);
            }
        }
    }
}
