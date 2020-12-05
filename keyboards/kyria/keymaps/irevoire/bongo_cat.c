// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.

#include <stdio.h>
#include QMK_KEYBOARD_H

#include "frame_manipulation.h"

char wpm_str[10];

static char CURRENT_FRAME[636] = { 0 };

static const char PROGMEM BASE_FRAME[636] = {
	0, 0, 126, 126, 24, 60, 102, 66, 0, 12, 28, 112, 112, 28, 12, 0, 116, 116, 20,
	20, 124, 104, 0, 124, 124, 0, 112, 120, 44, 36, 124, 124, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 0, 0, 0, 0, 0, 128, 64, 64, 32,
	32, 32, 32, 16, 16, 16, 16, 8, 4, 2, 1, 1, 2, 12, 48, 64, 128, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 192,
	96, 48, 24, 12, 132, 198, 98, 35, 51, 17, 145, 113, 241, 113, 145, 17, 51, 35,
	98, 198, 132, 12, 24, 48, 96, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 30, 225, 0, 0, 1, 1, 2, 2, 1, 0, 0, 0, 0, 128, 128, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 128, 0, 48, 48, 0, 192, 193, 193, 194, 4, 8, 16, 32, 64, 128, 0,
	0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8,
	8, 8, 8, 8, 196, 4, 196, 4, 196, 2, 194, 2, 194, 1, 1, 1, 1, 0, 0, 0, 0, 0,
	252, 15, 1, 0, 248, 14, 31, 109, 140, 148, 148, 164, 166, 249, 224, 255, 224,
	249, 166, 164, 148, 148, 140, 109, 31, 14, 248, 0, 1, 15, 252, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 112, 12, 3, 0, 0, 0, 0, 0, 0, 0, 12, 12,
	12, 13, 1, 0, 64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8, 8, 8, 4, 4, 8, 8, 16,
	16, 16, 16, 16, 17, 15, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 170, 170, 255, 255, 195, 191, 127, 3, 127, 191, 195, 255, 255, 170, 170,
	0, 0, 0, 0, 0, 0, 31, 120, 192, 0, 15, 56, 124, 219, 152, 20, 20, 18, 50, 207,
	3, 255, 3, 207, 50, 18, 20, 20, 152, 219, 124, 56, 15, 0, 192, 120, 31, 16,
	16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2,
	4, 4, 8, 8, 8, 8, 8, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	130, 135, 31, 7, 159, 7, 28, 7, 159, 7, 159, 7, 2, 130, 0, 0, 0, 0, 32, 16,
	16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98, 102, 68, 68, 71, 71, 71, 68, 68,
	102, 98, 35, 49, 16, 24, 12, 6, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 8, 8, 23, 0, 15, 1, 2, 1, 15, 0, 15,
	2, 5, 8
};
#define IDLE4 BASE_FRAME
static const char PROGMEM BASE_TO_IDLE1[36] = {
	51, 0, 2, 128, 16, 0, 131, 248, 252, 250, 2, 253, 130, 254, 4, 101, 0, 132, 6,
	125, 126, 254, 2, 255, 121, 0, 131, 192, 56, 8, 128, 0, 128, 0, 73, 0
};
// We want to repeat the next frame twice so we are going to make a fake IDLE2 frame
#define BASE_TO_IDLE2 BASE_TO_IDLE1
static const char PROGMEM BASE_TO_IDLE3[92] = {
	51, 0, 2, 128, 5, 0, 129, 128, 2, 192, 4, 224, 4, 240, 131, 248, 252, 254, 2,
	255, 133, 254, 244, 208, 192, 128, 98, 0, 130, 226, 31, 4, 255, 2, 254, 2,
	255, 3, 0, 2, 128, 9, 0, 130, 128, 0, 2, 208, 129, 0, 3, 63, 135, 62, 252,
	248, 240, 224, 192, 128, 90, 0, 130, 243, 253, 7, 0, 3, 244, 130, 242, 254, 3,
	0, 129, 255, 2, 254, 3, 255, 129, 254, 4, 0, 4, 255, 128, 0, 128, 0, 42, 0
};
// BASE_TO_IDLE4 frame is almost empty since IDLE4 is already used as the base
static const char PROGMEM BASE_TO_IDLE4[10] = {
	128, 0, 128, 0, 128, 0, 128, 0, 124, 0
};
static const char PROGMEM BASE_TO_IDLE5[29] = {
	51, 0, 2, 128, 17, 0, 130, 252, 254, 2, 255, 131, 0, 8, 248, 100, 0, 129, 2,
	5, 255, 128, 0, 128, 0, 128, 0, 69, 0
};
static const char PROGMEM BASE_TO_PREP[62] = {
	128, 0, 57, 0, 3, 128, 18, 0, 2, 192, 137, 224, 168, 254, 255, 223, 235, 63,
	246, 132, 93, 0, 137, 232, 250, 251, 104, 103, 136, 73, 144, 204, 2, 192, 130,
	0, 128, 13, 0, 2, 4, 2, 12, 3, 14, 130, 16, 14, 96, 0, 2, 2, 2, 4, 5, 8, 129,
	7, 128, 0, 57, 0
};
static const char PROGMEM BASE_TO_TAP1[84] = {
	86, 0, 4, 8, 5, 0, 2, 128, 88, 0, 3, 128, 18, 0, 4, 192, 4, 0, 129, 253, 2,
	249, 133, 255, 0, 200, 196, 194, 3, 225, 130, 241, 244, 83, 0, 137, 232, 250,
	251, 104, 103, 136, 201, 144, 204, 2, 192, 130, 0, 128, 23, 0, 130, 196, 132,
	5, 4, 130, 196, 244, 61, 0, 129, 224, 24, 0, 2, 2, 2, 4, 5, 8, 129, 7, 26, 0,
	129, 255, 2, 253, 128, 0, 28, 0
};
static const char PROGMEM BASE_TO_TAP2[65] = {
	128, 0, 78, 0, 2, 192, 137, 224, 168, 254, 255, 223, 235, 63, 246, 132, 98, 0,
	4, 12, 17, 0, 2, 4, 2, 12, 3, 14, 130, 16, 14, 88, 0, 6, 136, 130, 200, 208,
	7, 0, 4, 128, 113, 0, 135, 208, 136, 132, 2, 1, 193, 249, 4, 0, 2, 1, 2, 129,
	132, 193, 194, 228, 232, 52, 0
};

static const char *BASE_TO_IDLE[5] = { BASE_TO_IDLE1, BASE_TO_IDLE2,  BASE_TO_IDLE3,  BASE_TO_IDLE4,  BASE_TO_IDLE5 }; 
static const char *BASE_TO_TAP[2] = { BASE_TO_TAP1, BASE_TO_TAP2 }; 

// WPM-responsive animation stuff here
#define IDLE_FRAMES  5
#define IDLE_SPEED 40 // below this wpm value your animation will idle

#define TAP_FRAMES 2
#define TAP_SPEED 60 // above this wpm value typing animation to triggere

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
uint8_t current_tap_frame = 0;

/// in this function we'll uncompress the frame to the current frame and then
/// undiff it with the base frame to generate the new frame
static void setup_current_frame(const char *compressed, size_t len) {
	uncompress(compressed, len, CURRENT_FRAME);
	undiff(BASE_FRAME, CURRENT_FRAME, sizeof(BASE_FRAME));
}

static void animation_phase(void) {
	if(get_current_wpm() <= IDLE_SPEED){
		current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
		setup_current_frame(BASE_TO_IDLE[current_idle_frame],
				sizeof(BASE_TO_IDLE[current_idle_frame]));
		oled_write_raw_P(CURRENT_FRAME, sizeof(CURRENT_FRAME));
	}
	if(get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED){
		setup_current_frame(BASE_TO_PREP, sizeof(BASE_TO_PREP));
		oled_write_raw_P(CURRENT_FRAME, sizeof(CURRENT_FRAME));
	}
	if(get_current_wpm() >= TAP_SPEED){
		current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
		setup_current_frame(BASE_TO_TAP[current_tap_frame],
				sizeof(BASE_TO_TAP[current_tap_frame]));
		oled_write_raw_P(CURRENT_FRAME, sizeof(CURRENT_FRAME));
	}
}

void bongo_render_anim(void) {
	if(get_current_wpm() != 000) {
		oled_on(); // not essential but turns on animation OLED with any alpha keypress
		if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
			anim_timer = timer_read32();
			animation_phase();
		}
		anim_sleep = timer_read32();
	} else {
		if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
			oled_off();
		} else {
			if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
				anim_timer = timer_read32();
				animation_phase();
			}
		}
	}
}
