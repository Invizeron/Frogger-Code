#include "Sound.h"

void playMusic() {
	PlaySound("background.wav", NULL, SND_LOOP | SND_SYNC | SND_ASYNC);
}