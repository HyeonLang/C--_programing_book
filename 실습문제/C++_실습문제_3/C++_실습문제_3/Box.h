#ifndef BOX_H //헤더파일
#define BOX_H

class Box {
	int width, height;
	char fill; //박스 내부 채우는 문자
public:
	Box(int w, int h);
	void setFill(char f);
	void setSize(int w, int h);
	void draw();
};

#endif
