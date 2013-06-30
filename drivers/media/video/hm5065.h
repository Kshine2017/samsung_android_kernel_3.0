/*
 * Driver for HM5065 CMOS Image Sensor from Omnivision
 *
 * Copyright (C) 2012, Luo Jun <3869714@qq.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

 #define HM5065_SENSOR_ID    (0x039E)  

#define HM5065_PREVIEW_WIDTH		640
#define HM5065_PREVIEW_HEIGHT		480

#define HM5065_CAPTURE_WIDTH		2592
#define HM5065_CAPTURE_HEIGHT		1936  //1944

#define HM5065_DELAY 				0xff

typedef struct
{
	u16 reg;
	u8 val;
}HM5065_REG;



const static HM5065_REG hm5065_init_setting[] = 
{
	{0xffff ,0x01},
{0x9000 ,0x03},
{0xA000 ,0x90},
{0xA001 ,0x0C},
{0xA002 ,0x56},
{0xA003 ,0xE0},
{0xA004 ,0xFE},
{0xA005 ,0xA3},
{0xA006 ,0xE0},
{0xA007 ,0xFF},
{0xA008 ,0x12},
{0xA009 ,0x42},
{0xA00A ,0x85},
{0xA00B ,0x90},
{0xA00C ,0x01},
{0xA00D ,0xB7},
{0xA00E ,0xEE},
{0xA00F ,0xF0},
{0xA010 ,0xFC},
{0xA011 ,0xA3},
{0xA012 ,0xEF},
{0xA013 ,0xF0},
{0xA014 ,0xFD},
{0xA015 ,0x90},
{0xA016 ,0x06},
{0xA017 ,0x05},
{0xA018 ,0xE0},
{0xA019 ,0x75},
{0xA01A ,0xF0},
{0xA01B ,0x02},
{0xA01C ,0xA4},
{0xA01D ,0x2D},
{0xA01E ,0xFF},
{0xA01F ,0xE5},
{0xA020 ,0xF0},
{0xA021 ,0x3C},
{0xA022 ,0xFE},
{0xA023 ,0xAB},
{0xA024 ,0x07},
{0xA025 ,0xFA},
{0xA026 ,0x33},
{0xA027 ,0x95},
{0xA028 ,0xE0},
{0xA029 ,0xF9},
{0xA02A ,0xF8},
{0xA02B ,0x90},
{0xA02C ,0x0B},
{0xA02D ,0x4B},
{0xA02E ,0xE0},
{0xA02F ,0xFE},
{0xA030 ,0xA3},
{0xA031 ,0xE0},
{0xA032 ,0xFF},
{0xA033 ,0xEE},
{0xA034 ,0x33},
{0xA035 ,0x95},
{0xA036 ,0xE0},
{0xA037 ,0xFD},
{0xA038 ,0xFC},
{0xA039 ,0x12},
{0xA03A ,0x0C},
{0xA03B ,0x7B},
{0xA03C ,0x90},
{0xA03D ,0x01},
{0xA03E ,0xB9},
{0xA03F ,0x12},
{0xA040 ,0x0E},
{0xA041 ,0x05},
{0xA042 ,0x90},
{0xA043 ,0x01},
{0xA044 ,0xB9},
{0xA045 ,0xE0},
{0xA046 ,0xFC},
{0xA047 ,0xA3},
{0xA048 ,0xE0},
{0xA049 ,0xFD},
{0xA04A ,0xA3},
{0xA04B ,0xE0},
{0xA04C ,0xFE},
{0xA04D ,0xA3},
{0xA04E ,0xE0},
{0xA04F ,0xFF},
{0xA050 ,0x78},
{0xA051 ,0x08},
{0xA052 ,0x12},
{0xA053 ,0x0D},
{0xA054 ,0xBF},
{0xA055 ,0xA8},
{0xA056 ,0x04},
{0xA057 ,0xA9},
{0xA058 ,0x05},
{0xA059 ,0xAA},
{0xA05A ,0x06},
{0xA05B ,0xAB},
{0xA05C ,0x07},
{0xA05D ,0x90},
{0xA05E ,0x0B},
{0xA05F ,0x49},
{0xA060 ,0xE0},
{0xA061 ,0xFE},
{0xA062 ,0xA3},
{0xA063 ,0xE0},
{0xA064 ,0xFF},
{0xA065 ,0xEE},
{0xA066 ,0x33},
{0xA067 ,0x95},
{0xA068 ,0xE0},
{0xA069 ,0xFD},
{0xA06A ,0xFC},
{0xA06B ,0xC3},
{0xA06C ,0xEF},
{0xA06D ,0x9B},
{0xA06E ,0xFF},
{0xA06F ,0xEE},
{0xA070 ,0x9A},
{0xA071 ,0xFE},
{0xA072 ,0xED},
{0xA073 ,0x99},
{0xA074 ,0xFD},
{0xA075 ,0xEC},
{0xA076 ,0x98},
{0xA077 ,0xFC},
{0xA078 ,0x78},
{0xA079 ,0x01},
{0xA07A ,0x12},
{0xA07B ,0x0D},
{0xA07C ,0xBF},
{0xA07D ,0x90},
{0xA07E ,0x0C},
{0xA07F ,0x4A},
{0xA080 ,0xE0},
{0xA081 ,0xFC},
{0xA082 ,0xA3},
{0xA083 ,0xE0},
{0xA084 ,0xF5},
{0xA085 ,0x82},
{0xA086 ,0x8C},
{0xA087 ,0x83},
{0xA088 ,0xC0},
{0xA089 ,0x83},
{0xA08A ,0xC0},
{0xA08B ,0x82},
{0xA08C ,0x90},
{0xA08D ,0x0B},
{0xA08E ,0x48},
{0xA08F ,0xE0},
{0xA090 ,0xD0},
{0xA091 ,0x82},
{0xA092 ,0xD0},
{0xA093 ,0x83},
{0xA094 ,0x75},
{0xA095 ,0xF0},
{0xA096 ,0x02},
{0xA097 ,0x12},
{0xA098 ,0x0E},
{0xA099 ,0x45},
{0xA09A ,0xEE},
{0xA09B ,0xF0},
{0xA09C ,0xA3},
{0xA09D ,0xEF},
{0xA09E ,0xF0},
{0xA09F ,0x02},
{0xA0A0 ,0xBA},
{0xA0A1 ,0xD8},
{0xA0A2 ,0x90},
{0xA0A3 ,0x30},
{0xA0A4 ,0x18},
{0xA0A5 ,0xe4},
{0xA0A6 ,0xf0},
{0xA0A7 ,0x74},
{0xA0A8 ,0x3f},
{0xA0A9 ,0xf0},
{0xA0AA ,0x22},
{0xA0BF ,0x90},
{0xA0C0 ,0x00},
{0xA0C1 ,0x5E},
{0xA0C2 ,0xE0},
{0xA0C3 ,0xFF},
{0xA0C4 ,0x70},
{0xA0C5 ,0x20},
{0xA0C6 ,0x90},
{0xA0C7 ,0x47},
{0xA0C8 ,0x04},
{0xA0C9 ,0x74},
{0xA0CA ,0x0A},
{0xA0CB ,0xF0},
{0xA0CC ,0xA3},
{0xA0CD ,0x74},
{0xA0CE ,0x30},
{0xA0CF ,0xF0},
{0xA0D0 ,0x90},
{0xA0D1 ,0x47},
{0xA0D2 ,0x0C},
{0xA0D3 ,0x74},
{0xA0D4 ,0x07},
{0xA0D5 ,0xF0},
{0xA0D6 ,0xA3},
{0xA0D7 ,0x74},
{0xA0D8 ,0xA8},
{0xA0D9 ,0xF0},
{0xA0DA ,0x90},
{0xA0DB ,0x47},
{0xA0DC ,0xA4},
{0xA0DD ,0x74},
{0xA0DE ,0x01},
{0xA0DF ,0xF0},
{0xA0E0 ,0x90},
{0xA0E1 ,0x47},
{0xA0E2 ,0xA8},
{0xA0E3 ,0xF0},
{0xA0E4 ,0x80},
{0xA0E5 ,0x50},
{0xA0E6 ,0xEF},
{0xA0E7 ,0x64},
{0xA0E8 ,0x01},
{0xA0E9 ,0x60},
{0xA0EA ,0x04},
{0xA0EB ,0xEF},
{0xA0EC ,0xB4},
{0xA0ED ,0x03},
{0xA0EE ,0x20},
{0xA0EF ,0x90},
{0xA0F0 ,0x47},
{0xA0F1 ,0x04},
{0xA0F2 ,0x74},
{0xA0F3 ,0x05},
{0xA0F4 ,0xF0},
{0xA0F5 ,0xA3},
{0xA0F6 ,0x74},
{0xA0F7 ,0x18},
{0xA0F8 ,0xF0},
{0xA0F9 ,0x90},
{0xA0FA ,0x47},
{0xA0FB ,0x0C},
{0xA0FC ,0x74},
{0xA0FD ,0x03},
{0xA0FE ,0xF0},
{0xA0FF ,0xA3},
{0xA100 ,0x74},
{0xA101 ,0xD4},
{0xA102 ,0xF0},
{0xA103 ,0x90},
{0xA104 ,0x47},
{0xA105 ,0xA4},
{0xA106 ,0x74},
{0xA107 ,0x02},
{0xA108 ,0xF0},
{0xA109 ,0x90},
{0xA10A ,0x47},
{0xA10B ,0xA8},
{0xA10C ,0xF0},
{0xA10D ,0x80},
{0xA10E ,0x27},
{0xA10F ,0xEF},
{0xA110 ,0x64},
{0xA111 ,0x02},
{0xA112 ,0x60},
{0xA113 ,0x04},
{0xA114 ,0xEF},
{0xA115 ,0xB4},
{0xA116 ,0x04},
{0xA117 ,0x1E},
{0xA118 ,0x90},
{0xA119 ,0x47},
{0xA11A ,0x04},
{0xA11B ,0x74},
{0xA11C ,0x02},
{0xA11D ,0xF0},
{0xA11E ,0xA3},
{0xA11F ,0x74},
{0xA120 ,0x8C},
{0xA121 ,0xF0},
{0xA122 ,0x90},
{0xA123 ,0x47},
{0xA124 ,0x0C},
{0xA125 ,0x74},
{0xA126 ,0x01},
{0xA127 ,0xF0},
{0xA128 ,0xA3},
{0xA129 ,0x74},
{0xA12A ,0xEA},
{0xA12B ,0xF0},
{0xA12C ,0x90},
{0xA12D ,0x47},
{0xA12E ,0xA4},
{0xA12F ,0x74},
{0xA130 ,0x04},
{0xA131 ,0xF0},
{0xA132 ,0x90},
{0xA133 ,0x47},
{0xA134 ,0xA8},
{0xA135 ,0xF0},
{0xA136 ,0x22},
{0xA137 ,0x74},
{0xA138 ,0x04},
{0xA139 ,0xF0},
{0xA13A ,0xA3},
{0xA13B ,0x74},
{0xA13C ,0x20},
{0xA13D ,0xF0},
{0xA13E ,0xE4},
{0xA13F ,0xF5},
{0xA140 ,0x22},
{0xA141 ,0xE5},
{0xA142 ,0x22},
{0xA143 ,0xC3},
{0xA144 ,0x94},
{0xA145 ,0x40},
{0xA146 ,0x40},
{0xA147 ,0x03},
{0xA148 ,0x02},
{0xA149 ,0xF1},
{0xA14A ,0xFD},
{0xA14B ,0x90},
{0xA14C ,0x0A},
{0xA14D ,0xBA},
{0xA14E ,0xE0},
{0xA14F ,0xFE},
{0xA150 ,0xA3},
{0xA151 ,0xE0},
{0xA152 ,0xFF},
{0xA153 ,0xF5},
{0xA154 ,0x82},
{0xA155 ,0x8E},
{0xA156 ,0x83},
{0xA157 ,0xE0},
{0xA158 ,0x54},
{0xA159 ,0x70},
{0xA15A ,0xFD},
{0xA15B ,0xC4},
{0xA15C ,0x54},
{0xA15D ,0x0F},
{0xA15E ,0xFD},
{0xA15F ,0x90},
{0xA160 ,0x0A},
{0xA161 ,0xBC},
{0xA162 ,0xE0},
{0xA163 ,0xFA},
{0xA164 ,0xA3},
{0xA165 ,0xE0},
{0xA166 ,0xF5},
{0xA167 ,0x82},
{0xA168 ,0x8A},
{0xA169 ,0x83},
{0xA16A ,0xED},
{0xA16B ,0xF0},
{0xA16C ,0x90},
{0xA16D ,0x0A},
{0xA16E ,0xBD},
{0xA16F ,0xE0},
{0xA170 ,0x04},
{0xA171 ,0xF0},
{0xA172 ,0x70},
{0xA173 ,0x06},
{0xA174 ,0x90},
{0xA175 ,0x0A},
{0xA176 ,0xBC},
{0xA177 ,0xE0},
{0xA178 ,0x04},
{0xA179 ,0xF0},
{0xA17A ,0x8F},
{0xA17B ,0x82},
{0xA17C ,0x8E},
{0xA17D ,0x83},
{0xA17E ,0xA3},
{0xA17F ,0xE0},
{0xA180 ,0xFF},
{0xA181 ,0x90},
{0xA182 ,0x0A},
{0xA183 ,0xBC},
{0xA184 ,0xE0},
{0xA185 ,0xFC},
{0xA186 ,0xA3},
{0xA187 ,0xE0},
{0xA188 ,0xF5},
{0xA189 ,0x82},
{0xA18A ,0x8C},
{0xA18B ,0x83},
{0xA18C ,0xEF},
{0xA18D ,0xF0},
{0xA18E ,0x90},
{0xA18F ,0x0A},
{0xA190 ,0xBD},
{0xA191 ,0xE0},
{0xA192 ,0x04},
{0xA193 ,0xF0},
{0xA194 ,0x70},
{0xA195 ,0x06},
{0xA196 ,0x90},
{0xA197 ,0x0A},
{0xA198 ,0xBC},
{0xA199 ,0xE0},
{0xA19A ,0x04},
{0xA19B ,0xF0},
{0xA19C ,0x90},
{0xA19D ,0x0A},
{0xA19E ,0xBA},
{0xA19F ,0xE0},
{0xA1A0 ,0xFE},
{0xA1A1 ,0xA3},
{0xA1A2 ,0xE0},
{0xA1A3 ,0xFF},
{0xA1A4 ,0xF5},
{0xA1A5 ,0x82},
{0xA1A6 ,0x8E},
{0xA1A7 ,0x83},
{0xA1A8 ,0xE0},
{0xA1A9 ,0x54},
{0xA1AA ,0x07},
{0xA1AB ,0xFD},
{0xA1AC ,0x90},
{0xA1AD ,0x0A},
{0xA1AE ,0xBC},
{0xA1AF ,0xE0},
{0xA1B0 ,0xFA},
{0xA1B1 ,0xA3},
{0xA1B2 ,0xE0},
{0xA1B3 ,0xF5},
{0xA1B4 ,0x82},
{0xA1B5 ,0x8A},
{0xA1B6 ,0x83},
{0xA1B7 ,0xED},
{0xA1B8 ,0xF0},
{0xA1B9 ,0x90},
{0xA1BA ,0x0A},
{0xA1BB ,0xBD},
{0xA1BC ,0xE0},
{0xA1BD ,0x04},
{0xA1BE ,0xF0},
{0xA1BF ,0x70},
{0xA1C0 ,0x06},
{0xA1C1 ,0x90},
{0xA1C2 ,0x0A},
{0xA1C3 ,0xBC},
{0xA1C4 ,0xE0},
{0xA1C5 ,0x04},
{0xA1C6 ,0xF0},
{0xA1C7 ,0x8F},
{0xA1C8 ,0x82},
{0xA1C9 ,0x8E},
{0xA1CA ,0x83},
{0xA1CB ,0xA3},
{0xA1CC ,0xA3},
{0xA1CD ,0xE0},
{0xA1CE ,0xFF},
{0xA1CF ,0x90},
{0xA1D0 ,0x0A},
{0xA1D1 ,0xBC},
{0xA1D2 ,0xE0},
{0xA1D3 ,0xFC},
{0xA1D4 ,0xA3},
{0xA1D5 ,0xE0},
{0xA1D6 ,0xF5},
{0xA1D7 ,0x82},
{0xA1D8 ,0x8C},
{0xA1D9 ,0x83},
{0xA1DA ,0xEF},
{0xA1DB ,0xF0},
{0xA1DC ,0x90},
{0xA1DD ,0x0A},
{0xA1DE ,0xBD},
{0xA1DF ,0xE0},
{0xA1E0 ,0x04},
{0xA1E1 ,0xF0},
{0xA1E2 ,0x70},
{0xA1E3 ,0x06},
{0xA1E4 ,0x90},
{0xA1E5 ,0x0A},
{0xA1E6 ,0xBC},
{0xA1E7 ,0xE0},
{0xA1E8 ,0x04},
{0xA1E9 ,0xF0},
{0xA1EA ,0x90},
{0xA1EB ,0x0A},
{0xA1EC ,0xBB},
{0xA1ED ,0xE0},
{0xA1EE ,0x24},
{0xA1EF ,0x03},
{0xA1F0 ,0xF0},
{0xA1F1 ,0x90},
{0xA1F2 ,0x0A},
{0xA1F3 ,0xBA},
{0xA1F4 ,0xE0},
{0xA1F5 ,0x34},
{0xA1F6 ,0x00},
{0xA1F7 ,0xF0},
{0xA1F8 ,0x05},
{0xA1F9 ,0x22},
{0xA1FA ,0x02},
{0xA1FB ,0xF1},
{0xA1FC ,0x41},
{0xA1FD ,0x90},
{0xA1FE ,0x0A},
{0xA1FF ,0xBA},
{0xA200 ,0x74},
{0xA201 ,0x0E},
{0xA202 ,0xF0},
{0xA203 ,0xA3},
{0xA204 ,0x74},
{0xA205 ,0xDC},
{0xA206 ,0xF0},
{0xA207 ,0xA3},
{0xA208 ,0x74},
{0xA209 ,0x05},
{0xA20A ,0xF0},
{0xA20B ,0xA3},
{0xA20C ,0x74},
{0xA20D ,0x61},
{0xA20E ,0xF0},
{0xA20F ,0x90},
{0xA210 ,0x0A},
{0xA211 ,0xBA},
{0xA212 ,0xE0},
{0xA213 ,0xFE},
{0xA214 ,0xA3},
{0xA215 ,0xE0},
{0xA216 ,0xAA},
{0xA217 ,0x06},
{0xA218 ,0xF9},
{0xA219 ,0x7B},
{0xA21A ,0x01},
{0xA21B ,0xC0},
{0xA21C ,0x02},
{0xA21D ,0xA3},
{0xA21E ,0xE0},
{0xA21F ,0xFE},
{0xA220 ,0xA3},
{0xA221 ,0xE0},
{0xA222 ,0xAA},
{0xA223 ,0x06},
{0xA224 ,0xF8},
{0xA225 ,0xAC},
{0xA226 ,0x02},
{0xA227 ,0x7D},
{0xA228 ,0x01},
{0xA229 ,0xD0},
{0xA22A ,0x02},
{0xA22B ,0x7E},
{0xA22C ,0x00},
{0xA22D ,0x7F},
{0xA22E ,0x04},
{0xA22F ,0x12},
{0xA230 ,0x0F},
{0xA231 ,0x6F},
{0xA232 ,0x02},
{0xA233 ,0x66},
{0xA234 ,0xD9},
{0xA235 ,0x90},
{0xA236 ,0x07},
{0xA237 ,0xD0},
{0xA238 ,0x02},
{0xA239 ,0xA2},
{0xA23A ,0x69},
{0xA240 ,0x02},
{0xA241 ,0x21},
{0xA242 ,0x7F},
{0xA243 ,0x02},
{0xA244 ,0x21},
{0xA245 ,0xF4},
{0xA246 ,0x02},
{0xA247 ,0xA6},
{0xA248 ,0x15},
{0xA249 ,0x60},
{0xA24A ,0x0A},
{0xA24B ,0xEF},
{0xA24C ,0xB4},
{0xA24D ,0x01},
{0xA24E ,0x16},
{0xA24F ,0x90},
{0xA250 ,0x00},
{0xA251 ,0x5D},
{0xA252 ,0xE0},
{0xA253 ,0x70},
{0xA254 ,0x10},
{0xA255 ,0x12},
{0xA256 ,0x26},
{0xA257 ,0xC8},
{0xA258 ,0x90},
{0xA259 ,0x00},
{0xA25A ,0x11},
{0xA25B ,0x74},
{0xA25C ,0x30},
{0xA25D ,0xF0},
{0xA25E ,0x90},
{0xA25F ,0x00},
{0xA260 ,0x10},
{0xA261 ,0x74},
{0xA262 ,0x01},
{0xA263 ,0xF0},
{0xA264 ,0x22},
{0xA265 ,0x12},
{0xA266 ,0x25},
{0xA267 ,0xA8},
{0xA268 ,0x02},
{0xA269 ,0x29},
{0xA26A ,0xFC},
{0xA26B ,0x44},
{0xA26C ,0x18},
{0xA26D ,0xF0},
{0xA26E ,0x90},
{0xA26F ,0x72},
{0xA270 ,0x18},
{0xA271 ,0xE0},
{0xA272 ,0x44},
{0xA273 ,0x18},
{0xA274 ,0xF0},
{0xA275 ,0x00},
{0xA276 ,0x00},
{0xA277 ,0x00},
{0xA278 ,0x00},
{0xA279 ,0x00},
{0xA27A ,0x00},
{0xA27B ,0x90},
{0xA27C ,0x72},
{0xA27D ,0x08},
{0xA27E ,0xE0},
{0xA27F ,0x44},
{0xA280 ,0x10},
{0xA281 ,0xF0},
{0xA282 ,0x90},
{0xA283 ,0x72},
{0xA284 ,0x14},
{0xA285 ,0xE0},
{0xA286 ,0x54},
{0xA287 ,0xFD},
{0xA288 ,0xF0},
{0xA289 ,0x22},
{0xA29B ,0xF0},
{0xA29C ,0xD3},
{0xA29D ,0x90},
{0xA29E ,0x07},
{0xA29F ,0x91},
{0xA2A0 ,0xE0},
{0xA2A1 ,0x94},
{0xA2A2 ,0x21},
{0xA2A3 ,0x90},
{0xA2A4 ,0x07},
{0xA2A5 ,0x90},
{0xA2A6 ,0xE0},
{0xA2A7 ,0x64},
{0xA2A8 ,0x80},
{0xA2A9 ,0x94},
{0xA2AA ,0x81},
{0xA2AB ,0x40},
{0xA2AC ,0x08},
{0xA2AD ,0x90},
{0xA2AE ,0x07},
{0xA2AF ,0xCB},
{0xA2B0 ,0x74},
{0xA2B1 ,0xFF},
{0xA2B2 ,0xF0},
{0xA2B3 ,0x80},
{0xA2B4 ,0x06},
{0xA2B5 ,0x90},
{0xA2B6 ,0x07},
{0xA2B7 ,0xCB},
{0xA2B8 ,0x74},
{0xA2B9 ,0x01},
{0xA2BA ,0xF0},
{0xA2BB ,0x02},
{0xA2BC ,0xB5},
{0xA2BD ,0xC3},
{0xA2BE ,0x90},
{0xA2BF ,0x08},
{0xA2C0 ,0x34},
{0xA2C1 ,0xE0},
{0xA2C2 ,0xFC},
{0xA2C3 ,0xA3},
{0xA2C4 ,0xE0},
{0xA2C5 ,0xFD},
{0xA2C6 ,0xA3},
{0xA2C7 ,0xE0},
{0xA2C8 ,0xFE},
{0xA2C9 ,0xA3},
{0xA2CA ,0xE0},
{0xA2CB ,0xFF},
{0xA2CC ,0x90},
{0xA2CD ,0x07},
{0xA2CE ,0xD0},
{0xA2CF ,0xE0},
{0xA2D0 ,0xF8},
{0xA2D1 ,0xA3},
{0xA2D2 ,0xE0},
{0xA2D3 ,0xF9},
{0xA2D4 ,0xA3},
{0xA2D5 ,0xE0},
{0xA2D6 ,0xFA},
{0xA2D7 ,0xA3},
{0xA2D8 ,0xE0},
{0xA2D9 ,0xFB},
{0xA2DA ,0xD3},
{0xA2DB ,0x12},
{0xA2DC ,0x0D},
{0xA2DD ,0xAE},
{0xA2DE ,0x40},
{0xA2DF ,0x0B},
{0xA2E0 ,0x12},
{0xA2E1 ,0xB5},
{0xA2E2 ,0x49},
{0xA2E3 ,0x90},
{0xA2E4 ,0x07},
{0xA2E5 ,0xA4},
{0xA2E6 ,0x74},
{0xA2E7 ,0x02},
{0xA2E8 ,0xF0},
{0xA2E9 ,0x80},
{0xA2EA ,0x09},
{0xA2EB ,0x12},
{0xA2EC ,0xB7},
{0xA2ED ,0x51},
{0xA2EE ,0x90},
{0xA2EF ,0x07},
{0xA2F0 ,0xA4},
{0xA2F1 ,0x74},
{0xA2F2 ,0x05},
{0xA2F3 ,0xF0},
{0xA2F4 ,0x02},
{0xA2F5 ,0xA2},
{0xA2F6 ,0xDA},
{0xA2F7 ,0x90},
{0xA2F8 ,0x0E},
{0xA2F9 ,0xE0},
{0xA2FA ,0xE0},
{0xA2FB ,0xFD},
{0xA2FC ,0xA3},
{0xA2FD ,0xE0},
{0xA2FE ,0x90},
{0xA2FF ,0x02},
{0xA300 ,0xA2},
{0xA301 ,0xCD},
{0xA302 ,0xF0},
{0xA303 ,0xA3},
{0xA304 ,0xED},
{0xA305 ,0xF0},
{0xA306 ,0x90},
{0xA307 ,0x0E},
{0xA308 ,0xE2},
{0xA309 ,0xE0},
{0xA30A ,0xFD},
{0xA30B ,0xA3},
{0xA30C ,0xE0},
{0xA30D ,0x90},
{0xA30E ,0x02},
{0xA30F ,0xA8},
{0xA310 ,0xCD},
{0xA311 ,0xF0},
{0xA312 ,0xA3},
{0xA313 ,0xED},
{0xA314 ,0xF0},
{0xA315 ,0xE4},
{0xA316 ,0x90},
{0xA317 ,0x06},
{0xA318 ,0x38},
{0xA319 ,0xF0},
{0xA31A ,0x02},
{0xA31B ,0x67},
{0xA31C ,0x63},
{0xA31D ,0x90},
{0xA31E ,0x0E},
{0xA31F ,0xE8},
{0xA320 ,0xE0},
{0xA321 ,0x90},
{0xA322 ,0x02},
{0xA323 ,0x62},
{0xA324 ,0xF0},
{0xA325 ,0x90},
{0xA326 ,0x0E},
{0xA327 ,0xE9},
{0xA328 ,0xE0},
{0xA329 ,0x90},
{0xA32A ,0x02},
{0xA32B ,0x63},
{0xA32C ,0xF0},
{0xA32D ,0x02},
{0xA32E ,0x67},
{0xA32F ,0x1F},
{0xA33B ,0x90},
{0xA33C ,0x0E},
{0xA33D ,0x14},
{0xA33E ,0xE0},
{0xA33F ,0xFE},
{0xA340 ,0xA3},
{0xA341 ,0xE0},
{0xA342 ,0xFF},
{0xA343 ,0x90},
{0xA344 ,0x06},
{0xA345 ,0xD9},
{0xA346 ,0xEE},
{0xA347 ,0xF0},
{0xA348 ,0xA3},
{0xA349 ,0xEF},
{0xA34A ,0xF0},
{0xA34B ,0x90},
{0xA34C ,0x0E},
{0xA34D ,0x18},
{0xA34E ,0xE0},
{0xA34F ,0xFD},
{0xA350 ,0x7C},
{0xA351 ,0x00},
{0xA352 ,0xC3},
{0xA353 ,0xEF},
{0xA354 ,0x9D},
{0xA355 ,0xEE},
{0xA356 ,0x9C},
{0xA357 ,0x50},
{0xA358 ,0x09},
{0xA359 ,0xE4},
{0xA35A ,0x90},
{0xA35B ,0x06},
{0xA35C ,0xD7},
{0xA35D ,0xF0},
{0xA35E ,0xA3},
{0xA35F ,0xF0},
{0xA360 ,0x80},
{0xA361 ,0x13},
{0xA362 ,0xC3},
{0xA363 ,0x90},
{0xA364 ,0x06},
{0xA365 ,0xDA},
{0xA366 ,0xE0},
{0xA367 ,0x9D},
{0xA368 ,0xFE},
{0xA369 ,0x90},
{0xA36A ,0x06},
{0xA36B ,0xD9},
{0xA36C ,0xE0},
{0xA36D ,0x9C},
{0xA36E ,0x90},
{0xA36F ,0x06},
{0xA370 ,0xD7},
{0xA371 ,0xF0},
{0xA372 ,0xA3},
{0xA373 ,0xCE},
{0xA374 ,0xF0},
{0xA375 ,0x90},
{0xA376 ,0x0E},
{0xA377 ,0x18},
{0xA378 ,0xE0},
{0xA379 ,0xF9},
{0xA37A ,0xFF},
{0xA37B ,0x90},
{0xA37C ,0x06},
{0xA37D ,0xC2},
{0xA37E ,0xE0},
{0xA37F ,0xFC},
{0xA380 ,0xA3},
{0xA381 ,0xE0},
{0xA382 ,0xFD},
{0xA383 ,0xC3},
{0xA384 ,0x9F},
{0xA385 ,0xFF},
{0xA386 ,0xEC},
{0xA387 ,0x94},
{0xA388 ,0x00},
{0xA389 ,0xFE},
{0xA38A ,0x90},
{0xA38B ,0x0E},
{0xA38C ,0x16},
{0xA38D ,0xE0},
{0xA38E ,0xFA},
{0xA38F ,0xA3},
{0xA390 ,0xE0},
{0xA391 ,0xFB},
{0xA392 ,0xD3},
{0xA393 ,0x9F},
{0xA394 ,0xEA},
{0xA395 ,0x9E},
{0xA396 ,0x40},
{0xA397 ,0x0A},
{0xA398 ,0x90},
{0xA399 ,0x06},
{0xA39A ,0xD5},
{0xA39B ,0xEC},
{0xA39C ,0xF0},
{0xA39D ,0xA3},
{0xA39E ,0xED},
{0xA39F ,0xF0},
{0xA3A0 ,0x80},
{0xA3A1 ,0x0E},
{0xA3A2 ,0xE9},
{0xA3A3 ,0x7E},
{0xA3A4 ,0x00},
{0xA3A5 ,0x2B},
{0xA3A6 ,0xFF},
{0xA3A7 ,0xEE},
{0xA3A8 ,0x3A},
{0xA3A9 ,0x90},
{0xA3AA ,0x06},
{0xA3AB ,0xD5},
{0xA3AC ,0xF0},
{0xA3AD ,0xA3},
{0xA3AE ,0xEF},
{0xA3AF ,0xF0},
{0xA3B0 ,0xE9},
{0xA3B1 ,0xFB},
{0xA3B2 ,0x7A},
{0xA3B3 ,0x00},
{0xA3B4 ,0x90},
{0xA3B5 ,0x0E},
{0xA3B6 ,0x15},
{0xA3B7 ,0xE0},
{0xA3B8 ,0x2B},
{0xA3B9 ,0xFE},
{0xA3BA ,0x90},
{0xA3BB ,0x0E},
{0xA3BC ,0x14},
{0xA3BD ,0xE0},
{0xA3BE ,0x3A},
{0xA3BF ,0x90},
{0xA3C0 ,0x06},
{0xA3C1 ,0xE1},
{0xA3C2 ,0xF0},
{0xA3C3 ,0xA3},
{0xA3C4 ,0xCE},
{0xA3C5 ,0xF0},
{0xA3C6 ,0xC3},
{0xA3C7 ,0x90},
{0xA3C8 ,0x0E},
{0xA3C9 ,0x17},
{0xA3CA ,0xE0},
{0xA3CB ,0x9B},
{0xA3CC ,0xFE},
{0xA3CD ,0x90},
{0xA3CE ,0x0E},
{0xA3CF ,0x16},
{0xA3D0 ,0x02},
{0xA3D1 ,0x20},
{0xA3D2 ,0xD5},
{0xA3D3 ,0x90},
{0xA3d4 ,0x0E},
{0xA3d5 ,0xE4},
{0xA3d6 ,0xE0},
{0xA3d7 ,0x90},
{0xA3d8 ,0x02},
{0xA3d9 ,0x66},
{0xA3da ,0xF0},
{0xA3DB ,0x90},
{0xA3dc ,0x0E},
{0xA3dd ,0xE5},
{0xA3de ,0xE0},
{0xA3df ,0x90},
{0xA3e0 ,0x02},
{0xA3e1 ,0x64},
{0xA3e2 ,0xF0},
{0xA3e3 ,0x90},
{0xA3e4 ,0x0E},
{0xA3e5 ,0xE6},
{0xA3e6 ,0xE0},
{0xA3e7 ,0x90},
{0xA3e8 ,0x02},
{0xA3e9 ,0x65},
{0xA3ea ,0xF0},
{0xA3eb ,0x02},
{0xA3ec ,0x67},
{0xA3ed ,0xA5},
{0xA3f0 ,0x12},
{0xA3f1 ,0x47},
{0xA3f2 ,0x59},
{0xA3f3 ,0x90},
{0xA3f4 ,0x00},
{0xA3f5 ,0xB5},
{0xA3f6 ,0xE0},
{0xA3f7 ,0xB4},
{0xA3f8 ,0x02},
{0xA3f9 ,0x03},
{0xA3fa ,0x12},
{0xA3fb ,0x47},
{0xA3fc ,0x59},
{0xA3fd ,0x02},
{0xA3fe ,0xC5},
{0xA3ff ,0xC3},
{0xA400 ,0x90},
{0xA401 ,0x00},
{0xA402 ,0x3D},
{0xA403 ,0xF0},
{0xA404 ,0x90},
{0xA405 ,0x00},
{0xA406 ,0x84},
{0xA407 ,0xE0},
{0xA408 ,0xFE},
{0xA409 ,0x90},
{0xA40A ,0x00},
{0xA40B ,0x3E},
{0xA40C ,0xF0},
{0xA40D ,0xEF},
{0xA40E ,0x70},
{0xA40F ,0x03},
{0xA410 ,0xEE},
{0xA411 ,0x60},
{0xA412 ,0x04},
{0xA413 ,0x7F},
{0xA414 ,0x01},
{0xA415 ,0x80},
{0xA416 ,0x02},
{0xA417 ,0x7F},
{0xA418 ,0x00},
{0xA419 ,0x90},
{0xA41A ,0x00},
{0xA41B ,0x3F},
{0xA41C ,0xEF},
{0xA41D ,0xF0},
{0xA41E ,0x02},
{0xA41F ,0x89},
{0xA420 ,0xD3},
{0xA421 ,0x90},
{0xA422 ,0x00},
{0xA423 ,0x12},
{0xA424 ,0xE0},
{0xA425 ,0xFF},
{0xA426 ,0x70},
{0xA427 ,0x0C},
{0xA428 ,0x90},
{0xA429 ,0x00},
{0xA42A ,0x46},
{0xA42B ,0xE0},
{0xA42C ,0xC3},
{0xA42D ,0x94},
{0xA42E ,0x07},
{0xA42F ,0x40},
{0xA430 ,0x03},
{0xA431 ,0x75},
{0xA432 ,0x2E},
{0xA433 ,0x02},
{0xA434 ,0xEF},
{0xA435 ,0xB4},
{0xA436 ,0x01},
{0xA437 ,0x0C},
{0xA438 ,0x90},
{0xA439 ,0x00},
{0xA43A ,0x66},
{0xA43B ,0xE0},
{0xA43C ,0xC3},
{0xA43D ,0x94},
{0xA43E ,0x07},
{0xA43F ,0x40},
{0xA440 ,0x03},
{0xA441 ,0x75},
{0xA442 ,0x2E},
{0xA443 ,0x02},
{0xA444 ,0x02},
{0xA445 ,0xA7},
{0xA446 ,0x9E},
{0xA447 ,0xC3},
{0xA448 ,0x90},
{0xA449 ,0x0B},
{0xA44A ,0x8F},
{0xA44B ,0xE0},
{0xA44C ,0x94},
{0xA44D ,0x80},
{0xA44E ,0x90},
{0xA44F ,0x0B},
{0xA450 ,0x8E},
{0xA451 ,0xE0},
{0xA452 ,0x94},
{0xA453 ,0x44},
{0xA454 ,0x40},
{0xA455 ,0x22},
{0xA456 ,0x90},
{0xA457 ,0x0B},
{0xA458 ,0x91},
{0xA459 ,0xE0},
{0xA45A ,0x94},
{0xA45B ,0x80},
{0xA45C ,0x90},
{0xA45D ,0x0B},
{0xA45E ,0x90},
{0xA45F ,0xE0},
{0xA460 ,0x94},
{0xA461 ,0x44},
{0xA462 ,0x40},
{0xA463 ,0x14},
{0xA464 ,0x90},
{0xA465 ,0x0B},
{0xA466 ,0x93},
{0xA467 ,0xE0},
{0xA468 ,0x94},
{0xA469 ,0x80},
{0xA46A ,0x90},
{0xA46B ,0x0B},
{0xA46C ,0x92},
{0xA46D ,0xE0},
{0xA46E ,0x94},
{0xA46F ,0x44},
{0xA470 ,0x40},
{0xA471 ,0x06},
{0xA472 ,0x90},
{0xA473 ,0x01},
{0xA474 ,0xA4},
{0xA475 ,0x02},
{0xA476 ,0x86},
{0xA477 ,0x57},
{0xA478 ,0x02},
{0xA479 ,0x86},
{0xA47A ,0x5C},
{0xA500 ,0xF5},
{0xA501 ,0x3B},
{0xA502 ,0x90},
{0xA503 ,0x06},
{0xA504 ,0x6C},
{0xA505 ,0xE0},
{0xA506 ,0xFF},
{0xA507 ,0xE5},
{0xA508 ,0x3B},
{0xA509 ,0xC3},
{0xA50A ,0x9F},
{0xA50B ,0x40},
{0xA50C ,0x03},
{0xA50D ,0x02},
{0xA50E ,0xF6},
{0xA50F ,0x0E},
{0xA510 ,0x90},
{0xA511 ,0x0B},
{0xA512 ,0xC6},
{0xA513 ,0xE0},
{0xA514 ,0x14},
{0xA515 ,0x60},
{0xA516 ,0x3C},
{0xA517 ,0x14},
{0xA518 ,0x60},
{0xA519 ,0x6B},
{0xA51A ,0x24},
{0xA51B ,0x02},
{0xA51C ,0x60},
{0xA51D ,0x03},
{0xA51E ,0x02},
{0xA51F ,0xF5},
{0xA520 ,0xB5},
{0xA521 ,0x90},
{0xA522 ,0x0A},
{0xA523 ,0x9A},
{0xA524 ,0xE0},
{0xA525 ,0xFB},
{0xA526 ,0xA3},
{0xA527 ,0xE0},
{0xA528 ,0xFA},
{0xA529 ,0xA3},
{0xA52A ,0xE0},
{0xA52B ,0xF9},
{0xA52C ,0x85},
{0xA52D ,0x3B},
{0xA52E ,0x82},
{0xA52F ,0x75},
{0xA530 ,0x83},
{0xA531 ,0x00},
{0xA532 ,0x12},
{0xA533 ,0x0A},
{0xA534 ,0xB8},
{0xA535 ,0xFF},
{0xA536 ,0x74},
{0xA537 ,0xAB},
{0xA538 ,0x25},
{0xA539 ,0x3B},
{0xA53A ,0xF5},
{0xA53B ,0x82},
{0xA53C ,0xE4},
{0xA53D ,0x34},
{0xA53E ,0x0A},
{0xA53F ,0xF5},
{0xA540 ,0x83},
{0xA541 ,0xE0},
{0xA542 ,0xFD},
{0xA543 ,0xC3},
{0xA544 ,0xEF},
{0xA545 ,0x9D},
{0xA546 ,0xFE},
{0xA547 ,0xE4},
{0xA548 ,0x94},
{0xA549 ,0x00},
{0xA54A ,0x90},
{0xA54B ,0x0B},
{0xA54C ,0xCA},
{0xA54D ,0xF0},
{0xA54E ,0xA3},
{0xA54F ,0xCE},
{0xA550 ,0xF0},
{0xA551 ,0x80},
{0xA552 ,0x62},
{0xA553 ,0x90},
{0xA554 ,0x0A},
{0xA555 ,0x9A},
{0xA556 ,0xE0},
{0xA557 ,0xFB},
{0xA558 ,0xA3},
{0xA559 ,0xE0},
{0xA55A ,0xFA},
{0xA55B ,0xA3},
{0xA55C ,0xE0},
{0xA55D ,0xF9},
{0xA55E ,0x85},
{0xA55F ,0x3B},
{0xA560 ,0x82},
{0xA561 ,0x75},
{0xA562 ,0x83},
{0xA563 ,0x00},
{0xA564 ,0x12},
{0xA565 ,0x0A},
{0xA566 ,0xB8},
{0xA567 ,0xFF},
{0xA568 ,0x74},
{0xA569 ,0x9D},
{0xA56A ,0x25},
{0xA56B ,0x3B},
{0xA56C ,0xF5},
{0xA56D ,0x82},
{0xA56E ,0xE4},
{0xA56F ,0x34},
{0xA570 ,0x0A},
{0xA571 ,0xF5},
{0xA572 ,0x83},
{0xA573 ,0xE0},
{0xA574 ,0xFD},
{0xA575 ,0xC3},
{0xA576 ,0xEF},
{0xA577 ,0x9D},
{0xA578 ,0xFE},
{0xA579 ,0xE4},
{0xA57A ,0x94},
{0xA57B ,0x00},
{0xA57C ,0x90},
{0xA57D ,0x0B},
{0xA57E ,0xCA},
{0xA57F ,0xF0},
{0xA580 ,0xA3},
{0xA581 ,0xCE},
{0xA582 ,0xF0},
{0xA583 ,0x80},
{0xA584 ,0x30},
{0xA585 ,0x90},
{0xA586 ,0x0A},
{0xA587 ,0x9A},
{0xA588 ,0xE0},
{0xA589 ,0xFB},
{0xA58A ,0xA3},
{0xA58B ,0xE0},
{0xA58C ,0xFA},
{0xA58D ,0xA3},
{0xA58E ,0xE0},
{0xA58F ,0xF9},
{0xA590 ,0x85},
{0xA591 ,0x3B},
{0xA592 ,0x82},
{0xA593 ,0x75},
{0xA594 ,0x83},
{0xA595 ,0x00},
{0xA596 ,0x12},
{0xA597 ,0x0A},
{0xA598 ,0xB8},
{0xA599 ,0xFF},
{0xA59A ,0x74},
{0xA59B ,0xA4},
{0xA59C ,0x25},
{0xA59D ,0x3B},
{0xA59E ,0xF5},
{0xA59F ,0x82},
{0xA5A0 ,0xE4},
{0xA5A1 ,0x34},
{0xA5A2 ,0x0A},
{0xA5A3 ,0xF5},
{0xA5A4 ,0x83},
{0xA5A5 ,0xE0},
{0xA5A6 ,0xFD},
{0xA5A7 ,0xC3},
{0xA5A8 ,0xEF},
{0xA5A9 ,0x9D},
{0xA5AA ,0xFE},
{0xA5AB ,0xE4},
{0xA5AC ,0x94},
{0xA5AD ,0x00},
{0xA5AE ,0x90},
{0xA5AF ,0x0B},
{0xA5B0 ,0xCA},
{0xA5B1 ,0xF0},
{0xA5B2 ,0xA3},
{0xA5B3 ,0xCE},
{0xA5B4 ,0xF0},
{0xA5B5 ,0x90},
{0xA5B6 ,0x07},
{0xA5B7 ,0x83},
{0xA5B8 ,0xE0},
{0xA5B9 ,0xFF},
{0xA5BA ,0x7E},
{0xA5BB ,0x00},
{0xA5BC ,0x90},
{0xA5BD ,0x0D},
{0xA5BE ,0xF6},
{0xA5BF ,0xEE},
{0xA5C0 ,0xF0},
{0xA5C1 ,0xA3},
{0xA5C2 ,0xEF},
{0xA5C3 ,0xF0},
{0xA5C4 ,0x90},
{0xA5C5 ,0x0B},
{0xA5C6 ,0xCA},
{0xA5C7 ,0xE0},
{0xA5C8 ,0xFC},
{0xA5C9 ,0xA3},
{0xA5CA ,0xE0},
{0xA5CB ,0xFD},
{0xA5CC ,0xD3},
{0xA5CD ,0x9F},
{0xA5CE ,0x74},
{0xA5CF ,0x80},
{0xA5D0 ,0xF8},
{0xA5D1 ,0xEC},
{0xA5D2 ,0x64},
{0xA5D3 ,0x80},
{0xA5D4 ,0x98},
{0xA5D5 ,0x40},
{0xA5D6 ,0x0C},
{0xA5D7 ,0x90},
{0xA5D8 ,0x0B},
{0xA5D9 ,0xC8},
{0xA5DA ,0xE0},
{0xA5DB ,0x04},
{0xA5DC ,0xF0},
{0xA5DD ,0xA3},
{0xA5DE ,0xE0},
{0xA5DF ,0x04},
{0xA5E0 ,0xF0},
{0xA5E1 ,0x80},
{0xA5E2 ,0x26},
{0xA5E3 ,0x90},
{0xA5E4 ,0x0D},
{0xA5E5 ,0xF6},
{0xA5E6 ,0xE0},
{0xA5E7 ,0xFE},
{0xA5E8 ,0xA3},
{0xA5E9 ,0xE0},
{0xA5EA ,0xFF},
{0xA5EB ,0xC3},
{0xA5EC ,0xE4},
{0xA5ED ,0x9F},
{0xA5EE ,0xFF},
{0xA5EF ,0xE4},
{0xA5F0 ,0x9E},
{0xA5F1 ,0xFE},
{0xA5F2 ,0xC3},
{0xA5F3 ,0xED},
{0xA5F4 ,0x9F},
{0xA5F5 ,0xEE},
{0xA5F6 ,0x64},
{0xA5F7 ,0x80},
{0xA5F8 ,0xF8},
{0xA5F9 ,0xEC},
{0xA5FA ,0x64},
{0xA5FB ,0x80},
{0xA5FC ,0x98},
{0xA5FD ,0x50},
{0xA5FE ,0x0A},
{0xA5FF ,0x90},
{0xA600 ,0x0B},
{0xA601 ,0xC8},
{0xA602 ,0xE0},
{0xA603 ,0x14},
{0xA604 ,0xF0},
{0xA605 ,0xA3},
{0xA606 ,0xE0},
{0xA607 ,0x04},
{0xA608 ,0xF0},
{0xA609 ,0x05},
{0xA60A ,0x3B},
{0xA60B ,0x02},
{0xA60C ,0xF5},
{0xA60D ,0x02},
{0xA60E ,0x90},
{0xA60F ,0x08},
{0xA610 ,0x58},
{0xA611 ,0x02},
{0xA612 ,0x9D},
{0xA613 ,0x50},
{0x9006 ,0xBA},
{0x9007 ,0x75},
{0x9008 ,0x00},
{0x9009 ,0x00},
{0x900A ,0x02},
{0x900D ,0x01},
{0x900E ,0xA2},
{0x900F ,0x8F},
{0x9010 ,0x00},
{0x9011 ,0xCB},
{0x9012 ,0x03},
{0x9016 ,0xE6},
{0x9017 ,0x6B},
{0x9018 ,0x02},
{0x9019 ,0x6B},
{0x901A ,0x02},
{0x901D ,0x01},
{0x901E ,0xAC},
{0x901F ,0x70},
{0x9020 ,0x00},
{0x9021 ,0xC5},
{0x9022 ,0x03},
{0x9026 ,0x9C},
{0x9027 ,0x5B},
{0x9028 ,0x00},
{0x9029 ,0xBF},
{0x902A ,0x02},
{0x902E ,0x60},
{0x902F ,0x1C},
{0x9030 ,0x01},
{0x9031 ,0x37},
{0x9032 ,0x02},
{0x9035 ,0x01},
{0x9036 ,0xBA},
{0x9037 ,0x70},
{0x9038 ,0x00},
{0x9039 ,0x00},
{0x903A ,0x03},
{0x903E ,0x21},
{0x903F ,0x3F},
{0x9040 ,0x02},
{0x9041 ,0x40},
{0x9042 ,0x02},
{0x9046 ,0x21},
{0x9047 ,0xEA},
{0x9048 ,0x02},
{0x9049 ,0x43},
{0x904A ,0x02},
{0x904E ,0xA6},
{0x904F ,0x12},
{0x9050 ,0x02},
{0x9051 ,0x46},
{0x9052 ,0x02},
{0x9056 ,0x29},
{0x9057 ,0xE3},
{0x9058 ,0x02},
{0x9059 ,0x49},
{0x905A ,0x02},
{0x905D ,0x01},
{0x905E ,0x9C},
{0x905F ,0x6E},
{0x9060 ,0x05},
{0x9061 ,0x00},
{0x9062 ,0x02},
{0x9065 ,0x01},
{0x9066 ,0xA2},
{0x9067 ,0x66},
{0x9068 ,0x02},
{0x9069 ,0x35},
{0x906A ,0x02},
{0x906D ,0x01},
{0x906E ,0xB5},
{0x906F ,0xC2},
{0x9070 ,0x02},
{0x9071 ,0x9B},
{0x9072 ,0x02},
{0x9075 ,0x01},
{0x9076 ,0xA2},
{0x9077 ,0xD4},
{0x9078 ,0x02},
{0x9079 ,0xBE},
{0x907A ,0x02},
{0x907D ,0x01},
{0x907E ,0xB7},
{0x907F ,0xEA},
{0x9080 ,0x00},
{0x9081 ,0x02},
{0x9082 ,0x03},
{0x9086 ,0x67},
{0x9087 ,0x31},
{0x9088 ,0x02},
{0x9089 ,0xF7},
{0x908A ,0x02},
{0x908E ,0x66},
{0x908F ,0xED},
{0x9090 ,0x03},
{0x9091 ,0x1D},
{0x9092 ,0x02},
{0x9096 ,0x67},
{0x9097 ,0x73},
{0x9098 ,0x03},
{0x9099 ,0xD3},
{0x909A ,0x02},
{0x909E ,0x20},
{0x909F ,0x40},
{0x90A0 ,0x03},
{0x90A1 ,0x3B},
{0x90A2 ,0x02},
{0x90A6 ,0xC5},
{0x90A7 ,0xC0},
{0x90A8 ,0x03},
{0x90A9 ,0xF0},
{0x90AA ,0x02},
{0x90AE ,0x41},
{0x90AF ,0xB3},
{0x90B0 ,0x00},
{0x90B1 ,0xA2},
{0x90B2 ,0x02},
{0x90B6 ,0x44},
{0x90B7 ,0xBA},
{0x90B8 ,0x00},
{0x90B9 ,0xF0},
{0x90BA ,0x03},
{0x90BE ,0x89},
{0x90BF ,0x99},
{0x90C0 ,0x04},
{0x90C1 ,0x00},
{0x90C2 ,0x02},
{0x90C6 ,0xA7},
{0x90C7 ,0x91},
{0x90C8 ,0x04},
{0x90C9 ,0x21},
{0x90CA ,0x02},
{0x90CE ,0x3A},
{0x90CF ,0x51},
{0x90D0 ,0x00},
{0x90D1 ,0xA2},
{0x90D2 ,0x02},
{0x90D6 ,0x86},
{0x90D7 ,0x54},
{0x90D8 ,0x04},
{0x90D9 ,0x47},
{0x90DA ,0x02},
{0x9000 ,0x01},
{0xffff ,0x00},
{0x0000, 0xcb},    
{0x0009 ,0x16},
{0x0012 ,0x00},
{0x0013 ,0x00},
{0x0016 ,0x00},
{0x0021 ,0x00},
{0x0022 ,0x01},
{0x0040 ,0x01},
{0x0041 ,0x04},
{0x0042 ,0x05},
{0x0043 ,0x00},
{0x0044 ,0x03},
{0x0045 ,0xC0},
{0x0046 ,0x02},
{0x0060 ,0x00},
{0x0061 ,0x00},
{0x0066 ,0x02},
{0x0083 ,0x00},
{0x0084 ,0x01},
{0x0085 ,0x02},
{0x00B2 ,0x4f},	//50
{0x00B3 ,0xc0},	//30
{0x00B4 ,0x01},
{0x00B5 ,0x01},
{0x00E8 ,0x01},
{0x00ED ,0x05},
{0x00EE ,0x1E},
{0x0129 ,0x00},
{0x0130 ,0x00},
{0x019C ,0x4B},
{0x019D ,0x20},
{0x01A0 ,0x01},
{0x01A1 ,0x80},
{0x01A2 ,0x80},
{0x01A3 ,0x80},
{0x5200 ,0x01},
{0x7000 ,0x0C},
{0x7101 ,0xC4},
{0x7102 ,0x09},
{0x7103 ,0x00},
{0x7104 ,0x00},
{0x7105 ,0x80},
{0x7158 ,0x00},
{0x0143 ,0x5F},
{0x0144 ,0x0D},
{0x02C2 ,0x00},
{0x02C3 ,0xC0},
{0x015E ,0x40},
{0x015F ,0x00},
{0x0390 ,0x01},
{0x0391 ,0x00},
{0x0392 ,0x00},
{0x03A0 ,0x14},
{0x03A1 ,0x00},
{0x03A2 ,0x5A},
{0x03A3 ,0xEE},
{0x03A4 ,0x69},
{0x03A5 ,0x49},
{0x03A6 ,0x3E},
{0x03A7 ,0x00},
{0x03A8 ,0x39},
{0x03A9 ,0x33},
{0x03B0 ,0x60},
{0x03B1 ,0x00},
{0x03B2 ,0x5A},
{0x03B3 ,0xEE},
{0x03B4 ,0x69},
{0x03B5 ,0x49},
{0x03B6 ,0x3E},
{0x03B7 ,0x00},
{0x03B8 ,0x3D},
{0x03B9 ,0x20},
{0x03C0 ,0x10},
{0x03C1 ,0x00},
{0x03C2 ,0x5A},
{0x03C3 ,0xEE},
{0x03C4 ,0x69},
{0x03C5 ,0x49},
{0x03C6 ,0x3A},
{0x03C7 ,0x80},
{0x03D0 ,0x64},
{0x03D1 ,0x00},
{0x03D2 ,0x5A},
{0x03D3 ,0xEE},
{0x03D4 ,0x69},
{0x03D5 ,0x49},
{0x03D6 ,0x34},
{0x03D7 ,0xD1},
{0x004C ,0x08},
{0x006C ,0x08},
{0x0350 ,0x00},
{0x0351 ,0x5A},
{0x0352 ,0xEE},
{0x0353 ,0x69},
{0x0354 ,0x49},
{0x0355 ,0x39},
{0x0356 ,0x6D},
{0x0357 ,0x19},
{0x0358 ,0x00},
{0x0359 ,0x3C},
{0x035A ,0x5A},
{0x035B ,0xEE},
{0x035C ,0x69},
{0x035D ,0x49},
{0x035E ,0x39},
{0x035F ,0x85},
{0x0049 ,0x14},
{0x004A ,0x0D},
{0x0069 ,0x14},
{0x006A ,0x0D},
{0x0090 ,0x5A},
{0x0091 ,0xEE},
{0x0092 ,0x3E},
{0x0093 ,0x00},
{0x0094 ,0x69},
{0x0095 ,0x49},
{0x0096 ,0x39},
{0x0097 ,0xCF},
{0x0098 ,0x00},
{0x00A0 ,0x5A},
{0x00A1 ,0xEE},
{0x00A2 ,0x3E},
{0x00A3 ,0x00},
{0x00A4 ,0x69},
{0x00A5 ,0x49},
{0x00A6 ,0x3B},
{0x00A7 ,0x80},
{0x00A8 ,0x00},
{0x0420 ,0x00},
{0x0421 ,0x91},
{0x0422 ,0xff},
{0x0423 ,0x94},
{0x0424 ,0x00},
{0x0425 ,0x7d},
{0x0426 ,0x00},
{0x0427 ,0xaa},
{0x0428 ,0x00},
{0x0429 ,0x39},
{0x042a ,0xff},
{0x042b ,0xb5},
{0x042c ,0x01},
{0x042d ,0xbc},
{0x042e ,0xff},
{0x042f ,0xd3},
{0x0430 ,0x00},
{0x0431 ,0xaf},
{0x0432 ,0xff},
{0x0433 ,0x5c},
{0x0434 ,0x00},
{0x0435 ,0xf8},
{0x0436 ,0x01},
{0x0437 ,0x1d},
{0x0438 ,0xff},
{0x0439 ,0x81},
{0x043a ,0xff},
{0x043b ,0x71},
{0x043c ,0x01},
{0x043d ,0x77},
{0x043e ,0xff},
{0x043f ,0x52},
{0x0450 ,0x00},
{0x0451 ,0x75},
{0x0452 ,0xff},
{0x0453 ,0x8e},
{0x0454 ,0x00},
{0x0455 ,0x6a},
{0x0456 ,0x00},
{0x0457 ,0x8a},
{0x0458 ,0xff},
{0x0459 ,0xa6},
{0x045a ,0xff},
{0x045b ,0xaa},
{0x045c ,0x00},
{0x045d ,0xe0},
{0x045e ,0xff},
{0x045f ,0xd0},
{0x0440 ,0x00},
{0x0441 ,0x5b},
{0x0442 ,0xff},
{0x0443 ,0x85},
{0x0444 ,0x00},
{0x0445 ,0x91},
{0x0446 ,0x00},
{0x0447 ,0x97},
{0x0448 ,0x00},
{0x0449 ,0x2c},
{0x044a ,0xff},
{0x044b ,0x31},
{0x044c ,0x01},
{0x044d ,0x5d},
{0x044e ,0xff},
{0x044f ,0xd6},
{0x0460 ,0x00},
{0x0461 ,0x94},
{0x0462 ,0xff},
{0x0463 ,0x96},
{0x0464 ,0x00},
{0x0465 ,0x7c},
{0x0466 ,0x00},
{0x0467 ,0xa5},
{0x0468 ,0x00},
{0x0469 ,0x42},
{0x046a ,0xff},
{0x046b ,0xb0},
{0x046c ,0x01},
{0x046d ,0xc2},
{0x046e ,0xff},
{0x046f ,0xdd},
{0x0470 ,0x00},
{0x0471 ,0xaa},
{0x0472 ,0xff},
{0x0473 ,0x65},
{0x0474 ,0x00},
{0x0475 ,0xea},
{0x0476 ,0x01},
{0x0477 ,0x0e},
{0x0478 ,0xff},
{0x0479 ,0x87},
{0x047a ,0xff},
{0x047b ,0x6f},
{0x047c ,0x01},
{0x047d ,0x68},
{0x047e ,0xff},
{0x047f ,0x68},
{0x0490 ,0x00},
{0x0491 ,0x7d},
{0x0492 ,0xff},
{0x0493 ,0x92},
{0x0494 ,0x00},
{0x0495 ,0x67},
{0x0496 ,0x00},
{0x0497 ,0x84},
{0x0498 ,0xff},
{0x0499 ,0xa3},
{0x049a ,0xff},
{0x049b ,0x98},
{0x049c ,0x01},
{0x049d ,0x00},
{0x049e ,0xff},
{0x049f ,0xe0},
{0x0480 ,0x00},
{0x0481 ,0x5a},
{0x0482 ,0xff},
{0x0483 ,0x8c},
{0x0484 ,0x00},
{0x0485 ,0x8d},
{0x0486 ,0x00},
{0x0487 ,0x94},
{0x0488 ,0x00},
{0x0489 ,0x37},
{0x048a ,0xff},
{0x048b ,0x1e},
{0x048c ,0x01},
{0x048d ,0x5d},
{0x048e ,0xff},
{0x048f ,0xdf},
{0x04a0 ,0x00},
{0x04a1 ,0x96},
{0x04a2 ,0xff},
{0x04a3 ,0x9f},
{0x04a4 ,0x00},
{0x04a5 ,0x75},
{0x04a6 ,0x00},
{0x04a7 ,0x96},
{0x04a8 ,0x00},
{0x04a9 ,0x3e},
{0x04aa ,0xff},
{0x04ab ,0x8a},
{0x04ac ,0x01},
{0x04ad ,0xc8},
{0x04ae ,0xff},
{0x04af ,0xf4},
{0x04b0 ,0x00},
{0x04b1 ,0x88},
{0x04b2 ,0xff},
{0x04b3 ,0x8a},
{0x04b4 ,0x00},
{0x04b5 ,0xa6},
{0x04b6 ,0x00},
{0x04b7 ,0xc2},
{0x04b8 ,0xff},
{0x04b9 ,0xa0},
{0x04ba ,0xff},
{0x04bb ,0x1b},
{0x04bc ,0x01},
{0x04bd ,0x53},
{0x04be ,0xff},
{0x04bf ,0xce},
{0x04d0 ,0x00},
{0x04d1 ,0x89},
{0x04d2 ,0xff},
{0x04d3 ,0x9b},
{0x04d4 ,0x00},
{0x04d5 ,0x5e},
{0x04d6 ,0x00},
{0x04d7 ,0x78},
{0x04d8 ,0xff},
{0x04d9 ,0x95},
{0x04da ,0xff},
{0x04db ,0x79},
{0x04dc ,0x01},
{0x04dd ,0x12},
{0x04de ,0xff},
{0x04df ,0xfc},
{0x04c0 ,0x00},
{0x04c1 ,0x5b},
{0x04c2 ,0xff},
{0x04c3 ,0x9c},
{0x04c4 ,0x00},
{0x04c5 ,0x82},
{0x04c6 ,0x00},
{0x04c7 ,0x8b},
{0x04c8 ,0x00},
{0x04c9 ,0x36},
{0x04ca ,0xfe},
{0x04cb ,0xfc},
{0x04cc ,0x01},
{0x04cd ,0x7c},
{0x04ce ,0xff},
{0x04cf ,0xf6},
{0x04e0 ,0x00},
{0x04e1 ,0xea},
{0x04e2 ,0xff},
{0x04e3 ,0xa6},
{0x04e4 ,0x00},
{0x04e5 ,0x76},
{0x04e6 ,0x00},
{0x04e7 ,0x94},
{0x04e8 ,0xff},
{0x04e9 ,0x8b},
{0x04ea ,0xff},
{0x04eb ,0xc0},
{0x04ec ,0x01},
{0x04ed ,0xc1},
{0x04ee ,0xff},
{0x04ef ,0xe8},
{0x04f0 ,0x00},
{0x04f1 ,0xfb},
{0x04f2 ,0xff},
{0x04f3 ,0x89},
{0x04f4 ,0x00},
{0x04f5 ,0xd0},
{0x04f6 ,0x00},
{0x04f7 ,0xd0},
{0x04f8 ,0x01},
{0x04f9 ,0x3e},
{0x04fa ,0xff},
{0x04fb ,0x86},
{0x04fc ,0x01},
{0x04fd ,0x1f},
{0x04fe ,0xff},
{0x04ff ,0x20},
{0x0510 ,0x00},
{0x0511 ,0xff},
{0x0512 ,0xff},
{0x0513 ,0xa2},
{0x0514 ,0x00},
{0x0515 ,0x60},
{0x0516 ,0x00},
{0x0517 ,0x7b},
{0x0518 ,0xff},
{0x0519 ,0x8a},
{0x051a ,0xff},
{0x051b ,0x82},
{0x051c ,0xff},
{0x051d ,0x8a},
{0x051e ,0x00},
{0x051f ,0x10},
{0x0500 ,0x00},
{0x0501 ,0xea},
{0x0502 ,0xff},
{0x0503 ,0x9d},
{0x0504 ,0x00},
{0x0505 ,0x7d},
{0x0506 ,0x00},
{0x0507 ,0x8e},
{0x0508 ,0xff},
{0x0509 ,0x8b},
{0x050a ,0xff},
{0x050b ,0x38},
{0x050c ,0x01},
{0x050d ,0x5c},
{0x050e ,0xff},
{0x050f ,0xeb},
{0x0561 ,0x0d},
{0x0562 ,0x0a},
{0x0563 ,0x06},
{0x0564 ,0x01},
{0x0324 ,0x39},
{0x0325 ,0xAE},
{0x0326 ,0x3A},
{0x0327 ,0x29},
{0x0328 ,0x3B},
{0x0329 ,0x0A},
{0x032A ,0x3B},
{0x032B ,0x62},
{0x0320 ,0x01},
{0x0321 ,0x04},
{0x0322 ,0x01},
{0x0323 ,0x01},
{0x0330 ,0x01},
{0x0384 ,0x00},
{0x0337 ,0x01},
{0x03EC ,0x39},
{0x03ED ,0x85},
{0x03FC ,0x3A},
{0x03FD ,0x14},
{0x040C ,0x3A},
{0x040D ,0xF6},
{0x041C ,0x3B},
{0x041D ,0x9A},
{0x03E0 ,0xB6},
{0x03E1 ,0x04},
{0x03E2 ,0xBB},
{0x03E3 ,0xE9},
{0x03E4 ,0xBC},
{0x03E5 ,0x70},
{0x03E6 ,0x37},
{0x03E7 ,0x02},
{0x03E8 ,0xBC},
{0x03E9 ,0x00},
{0x03EA ,0xBF},
{0x03EB ,0x12},
{0x03F0 ,0xBA},
{0x03F1 ,0x7B},
{0x03F2 ,0xBA},
{0x03F3 ,0x83},
{0x03F4 ,0xBB},
{0x03F5 ,0xBC},
{0x03F6 ,0x38},
{0x03F7 ,0x2D},
{0x03F8 ,0xBB},
{0x03F9 ,0x23},
{0x03FA ,0xBD},
{0x03FB ,0xAC},
{0x0400 ,0xBE},
{0x0401 ,0x96},
{0x0402 ,0xB9},
{0x0403 ,0xBE},
{0x0404 ,0xBB},
{0x0405 ,0x57},
{0x0406 ,0x3A},
{0x0407 ,0xBB},
{0x0408 ,0xB3},
{0x0409 ,0x17},
{0x040A ,0xBE},
{0x040B ,0x66},
{0x0410 ,0xBB},
{0x0411 ,0x2A},
{0x0412 ,0xBA},
{0x0413 ,0x00},
{0x0414 ,0xBB},
{0x0415 ,0x10},
{0x0416 ,0xB8},
{0x0417 ,0xCD},
{0x0418 ,0xB7},
{0x0419 ,0x5C},
{0x041A ,0xBB},
{0x041B ,0x6C},
{0x01f8 ,0x3c},
{0x01f9 ,0x00},
{0x01fa ,0x00},
{0x02a2 ,0x3e},
{0x02a3 ,0x00},
{0x02a4 ,0x3e},
{0x02a5 ,0x00},
{0x02a6 ,0x3e},
{0x02a7 ,0x00},
{0x02a8 ,0x3e},
{0x02a9 ,0x00},
{0x056c ,0x42},
{0x056d ,0x00},
{0x056e ,0x42},
{0x056f ,0x00},
{0x0570 ,0x42},
{0x0571 ,0x00},
{0x0572 ,0x42},
{0x0573 ,0x00},
{0x0081 ,0x58},
{0x0588 ,0x00},
{0x0589 ,0x5A},
{0x058A ,0xEE},
{0x058B ,0x69},
{0x058C ,0x49},
{0x058D ,0x3D},
{0x058E ,0x3D},
{0x0080 ,0x6C},
{0x0082 ,0x5A},
{0x065A ,0x00},
{0x06C9 ,0x01},
{0x06CD ,0x01},
{0x06CE ,0xBD},
{0x06CF ,0x00},
{0x06D0 ,0x93},
{0x06D1 ,0x02},
{0x06D2 ,0x30},
{0x06D3 ,0xD4},
{0x06D4 ,0x01},
{0x06D5 ,0x01},
{0x06D6 ,0xBD},
{0x06D7 ,0x00},
{0x06D8 ,0x93},
{0x06D9 ,0x00},
{0x06DA ,0x93},
{0x06DB ,0x59},
{0x06DC ,0x0d},
{0x0730 ,0x00},
{0x0731 ,0x00},
{0x0732 ,0x03},
{0x0733 ,0xFF},
{0x0734 ,0x03},
{0x0735 ,0x70},
{0x0755 ,0x01},
{0x0756 ,0x00},
{0x075B ,0x01},
{0x075E ,0x00},
{0x0764 ,0x01},
{0x0766 ,0x01},
{0x0768 ,0x01},
{0x076A ,0x00},
{0x0758 ,0x01},
{0x075C ,0x01},
{0x0770 ,0x98},
{0x0771 ,0x19},
{0x0772 ,0x1B},
{0x0774 ,0x01},
{0x0775 ,0x4a},
{0x0777 ,0x00},
{0x0778 ,0x45},
{0x0779 ,0x00},
{0x077A ,0x02},
{0x077D ,0x01},
{0x077E ,0x03},
{0x0783 ,0x10},
{0x0785 ,0x14},
{0x0788 ,0x04},
{0x0846 ,0x06},
{0x0847 ,0x05},
{0xC41A ,0x05},
{0xC423 ,0x11},
{0xC427 ,0x11},
{0x300B ,0x09},
{0x0010 ,0x01},
{0x0000, 0xcb}, 
{0x4708 ,0x00},
{0x4709 ,0x00},
{0x4710 ,0x00},
{0x4711 ,0x00},
};	

static const int hm5065_init_setting_size = sizeof(hm5065_init_setting)/sizeof(HM5065_REG);




const static HM5065_REG hm5065_regs_preview[] = 
{
    {0x0010, 0x02},
    {0x0000, 0xC8}, // delay cmd (0x0000, 0xC8)
		{0x00B2, 0x4f},	//50 
		{0x00B3, 0xc0},	//30   
    {0x00B5, 0x01},//  01=>02	35Mhz  ;01: 70MHz;02:35MHz
    {0x0030, 0x14}, //14
		{0x0083 ,0x00},    
		{0x0084 ,0x01},
		{0x0085, 0x02},	    
    {0x0000, 0xC8}, // delay cmd (0x0000, 0xC8)		
 

    {0x0040, 0x01},//0x01 	//	binning mode and subsampling mode for frame rate
    {0x0041, 0x04},//0x0A 	//	04 : VGA mode : 0A : self define ; 00 : 5M ;03:SVGA
    {0x0042, 0x02}, 	//	X:800 0x500=1280,0x0320=800
    {0x0043, 0x80}, 	//
    {0x0044, 0x01}, 	//	Y:600 0x03c0=960,0x0258=600
    {0x0045, 0xe0}, 	//
    
    //{0x0010, 0x01},
    //{0x0000, 0xC8}, // delay cmd (0x0000, 0xC8)	
    
    {0x00E8, 0x01},//AFR
    {0x00ED, 0x0A},//Min=10ps
    {0x00EE, 0x1E},//Max=30fps

    
    {0x0251, 0x02},//BLC ON

    {0x0128, 0x00},

    {0x01FA, 0x01},
    {0x01A5, 0x3E},                                                                              	
    {0x01A6, 0x33},                                                                              	
    {0x01A7, 0x3D},
    {0x01A8, 0x9A},
		{0x0010, 0x01},
		{0x0000, 0xC8},
    {0x070A, 0x01},
};

static const int hm5065_regs_preview_size = sizeof(hm5065_regs_preview)/sizeof(HM5065_REG);


const static HM5065_REG hm5065_regs_capture1M[] =
{
//	{0x0010, 0x02},
	{0x0000, 0xC8},  //
//	{0x00B2, 0x4F},	
//	{0x00B3, 0xCA},	
	{0x00B5, 0x02},
	{0x0030, 0x14},
	{0x0083 ,0x01},
	{0x0084 ,0x00},	
	//{0x0085, 0x01},	
	{0x0040, 0x00}, //Full size
	{0x0041, 0x02}, //02:SXGA
	{0x0042, 0x04}, //X:1024
	{0x0043, 0x00}, //
	{0x0044, 0x03}, //Y:768
	{0x0045, 0x00}, //

//	{0x0010, 0x01},//Stream on
	{0x0000, 0xC8},
	
	{0x0251, 0x01},//BLC off	
	
	{0x070A, 0x00},
	{0x0000, 0x64},  // delay 100ms
	

};

const static HM5065_REG hm5065_regs_capture2M[] =
{
//	{0x0010, 0x02},
	{0x0000, 0xC8},  //
//	{0x00B2, 0x4F},	
//	{0x00B3, 0xCA},	
	{0x00B5, 0x02},
	{0x0030, 0x14},
	{0x0083 ,0x01},
	{0x0084 ,0x00},	
	//{0x0085, 0x01},	
	{0x0040, 0x00}, //Full size
	{0x0041, 0x01}, //01:UXGA
	{0x0042, 0x06}, //X:1600
	{0x0043, 0x40}, //
	{0x0044, 0x04}, //Y:1200
	{0x0045, 0xB0}, //

//	{0x0010, 0x01},//Stream on
	{0x0000, 0xC8},
	
	{0x0251, 0x01},//BLC off	
	
	{0x070A, 0x00},
	{0x0000, 0x64},  // delay 100ms
	

};

const static HM5065_REG hm5065_regs_capture5M[] =
{
//	{0x0010, 0x02},
	{0x0000, 0xC8},  //
//	{0x00B2, 0x4F},	
//	{0x00B3, 0xCA},	
	{0x00B5, 0x02},
	{0x0030, 0x14},
	{0x0083 ,0x01},
	{0x0084 ,0x00},	
	//{0x0085, 0x01},	
	{0x0040, 0x00}, //Full size
	{0x0041, 0x00}, //00:5Mega
	{0x0042, 0x0A}, //X:2592
	{0x0043, 0x20}, //
	{0x0044, 0x07}, //Y:1936
	{0x0045, 0x90}, //

//	{0x0010, 0x01},//Stream on
	{0x0000, 0xC8},
	
	{0x0251, 0x01},//BLC off	
	
	{0x070A, 0x00},
	{0x0000, 0x64},  // delay 100ms
	

};

static const int hm5065_regs_capture1M_size = sizeof(hm5065_regs_capture1M)/sizeof(HM5065_REG);
static const int hm5065_regs_capture2M_size = sizeof(hm5065_regs_capture2M)/sizeof(HM5065_REG);
static const int hm5065_regs_capture5M_size = sizeof(hm5065_regs_capture5M)/sizeof(HM5065_REG);

const static HM5065_REG hm5065_regs_capture2[] = 
{
    {0x070C, 0x00},
 	  {0x0000, 0x64},  // delay 100ms   
    {0x070C, 0x05},
 	  {0x0000, 0x64},  // delay 100ms      
};

static const int hm5065_regs_capture2_size = sizeof(hm5065_regs_capture2)/sizeof(HM5065_REG);


enum
{
	HM5065_AWB_MODE_AUTO_ADVANCED,
	HM5065_AWB_MODE_AUTO_SIMPLE,
	HM5065_AWB_MODE_MANUAL_DAY,
	HM5065_AWB_MODE_MANUAL_A,
	HM5065_AWB_MODE_MANUAL_CWF,
	HM5065_AWB_MODE_MANUAL_CLOUDY
};



