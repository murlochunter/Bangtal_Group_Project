#define _CRT_SECURE_NO_WARNINGS
#include <bangtal.h>
#include <stdio.h>

extern ObjectID createObject(const char* name, SceneID scene, int x, int y, bool shown, float size);
extern SceneID g1_scene, g2_scene, g3_scene, g4_scene;
extern SoundID g4_mapbgm;
SceneID lobbyscene, mapscene;
ObjectID startbutton, endbutton, portalbutton[5];
SoundID introbgm;
// 0가 왼쪽위, 1이 왼쪽아래, 2가 오른쪽아래, 3이 오른쪽위, 4가 가운데
int portalX[5] = { 240, 305, 920, 930, 580 };
int portalY[5] = { 500, 170, 140, 490, 310 };
//게임 위치확인 (함수꼬이지 않게 하는용) 0은 로비 1,2,3,4,5 는 게임
int nowgamenum = 0;



// 마우스콜백함수
void lobby_mouseCallback(ObjectID object, int x, int y, MouseAction action) {

	if (object == startbutton) {
		enterScene(mapscene);
	}

	else if (object == portalbutton[0]) {
		enterScene(g1_scene);
		stopSound(introbgm);
		nowgamenum = 1;
	}

	else if (object == portalbutton[1]) {
		enterScene(g2_scene);
		stopSound(introbgm);
		nowgamenum = 2;
	}

	else if (object == portalbutton[2]) {
		enterScene(g3_scene);
		stopSound(introbgm);
		nowgamenum = 3;
	}

	else if (object == portalbutton[3]) {
		enterScene(g4_scene);
		stopSound(introbgm);
		playSound(g4_mapbgm);
		nowgamenum = 4;
	}

	else if (object == endbutton) {
		endGame();
	}
}

//타이머콜백함수
void lobby_timerCallback(TimerID timer) {

}

//사운드콜백함수
void lobby_soundCallback(SoundID sound) {
	if (sound == introbgm) {
		playSound(introbgm);
	}
}

//키보드콜백함수
void lobby_keyboardCallback(KeyCode code, KeyState state) {

}

void lobby_main() {
	
	lobbyscene = createScene("lobby", "image/startback.png");
	mapscene = createScene("map", "image/map.png");

	startbutton = createObject("image/start.png", lobbyscene, 150, 250, true, 0.7f);
	endbutton = createObject("image/end.png", lobbyscene, 150, 150, true, 0.7f);

	for (int i = 0; i < 5; i++) {
		portalbutton[i] = createObject("image/portal.png", mapscene, portalX[i], portalY[i], true, 0.2f);
	}

	introbgm = createSound("sound/lobby/intro.mp3");
	playSound(introbgm);


}