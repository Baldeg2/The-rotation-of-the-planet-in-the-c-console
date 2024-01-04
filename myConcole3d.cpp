#include <iostream>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "Functions.h"

int main() {
    int width = 120;
    int height = 30;
    float aspect = (float)width / height;
    float pixelAspect = 11.0f / 24.0f;
    char gradient[] = " .:!/r(I1Z4H9W8$@";
    int gradientSize = std::size(gradient) - 2;

    char* screen = new char[width * height + 1];
    screen[width * height] = '\0';

    for (int t = 0; t < 10000; t++) {
        vec3 light = norm(vec3(sin(t * 0.001), cos(t * 0.001), -1.0));
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                vec2 uv = vec2(i, j) / vec2(width, height) * 2.0f - 1.0f;
                uv.x *= aspect * pixelAspect;
                vec3 ro = vec3(-2, 0, 0);
                vec3 rd = norm(vec3(1, uv));
                char pixel = ' ';
                int color = 0;
                vec2 intersection = sphere(ro, rd, 1);
                if (intersection.x > 0) {
                    vec3 itPoint = ro + rd * intersection.x;
                    vec3 n = norm(itPoint);
                    float diff = dot(n, light);
                    color = (int)(diff * 20);
                }   
                color = clamp(color, 0, gradientSize);
                pixel = gradient[color];
                screen[i + j * width] = pixel;
            }
        }
        printf("%s", screen);
    }

    getchar();
}