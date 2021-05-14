#include <ToneUndef.h>
#ifndef TONE_VERIFIED
#define TONE_VERIFIED
#endif
#ifdef TONE_USE_INT
#define NOTE_C0  (16)
#define NOTE_CS0  (17)
#define NOTE_D0  (18)
#define NOTE_DS0  (19)
#define NOTE_E0  (20)
#define NOTE_F0  (21)
#define NOTE_FS0  (22)
#define NOTE_G0  (24)
#define NOTE_GS0  (25)
#define NOTE_A0  (27)
#define NOTE_AS0  (28)
#define NOTE_B0  (30)
#define NOTE_C1  (32)
#define NOTE_CS1  (34)
#define NOTE_D1  (36)
#define NOTE_DS1  (38)
#define NOTE_E1  (40)
#define NOTE_F1  (43)
#define NOTE_FS1  (45)
#define NOTE_G1  (48)
#define NOTE_GS1  (51)
#define NOTE_A1  (54)
#define NOTE_AS1  (57)
#define NOTE_B1  (61)
#define NOTE_C2  (64)
#define NOTE_CS2  (68)
#define NOTE_D2  (72)
#define NOTE_DS2  (77)
#define NOTE_E2  (81)
#define NOTE_F2  (86)
#define NOTE_FS2  (91)
#define NOTE_G2  (97)
#define NOTE_GS2  (102)
#define NOTE_A2  (109)
#define NOTE_AS2  (115)
#define NOTE_B2  (122)
#define NOTE_C3  (129)
#define NOTE_CS3  (137)
#define NOTE_D3  (145)
#define NOTE_DS3  (154)
#define NOTE_E3  (163)
#define NOTE_F3  (173)
#define NOTE_FS3  (183)
#define NOTE_G3  (194)
#define NOTE_GS3  (205)
#define NOTE_A3  (218)
#define NOTE_AS3  (230)
#define NOTE_B3  (244)
#define NOTE_C4  (259)
#define NOTE_CS4  (274)
#define NOTE_D4  (290)
#define NOTE_DS4  (308)
#define NOTE_E4  (326)
#define NOTE_F4  (346)
#define NOTE_FS4  (366)
#define NOTE_G4  (388)
#define NOTE_GS4  (411)
#define NOTE_A4  (436)
#define NOTE_AS4  (461)
#define NOTE_B4  (489)
#define NOTE_C5  (518)
#define NOTE_CS5  (549)
#define NOTE_D5  (581)
#define NOTE_DS5  (616)
#define NOTE_E5  (653)
#define NOTE_F5  (692)
#define NOTE_FS5  (733)
#define NOTE_G5  (776)
#define NOTE_GS5  (823)
#define NOTE_A5  (872)
#define NOTE_AS5  (923)
#define NOTE_B5  (978)
#define NOTE_C6  (1036)
#define NOTE_CS6  (1098)
#define NOTE_D6  (1163)
#define NOTE_DS6  (1233)
#define NOTE_E6  (1306)
#define NOTE_F6  (1384)
#define NOTE_FS6  (1466)
#define NOTE_G6  (1553)
#define NOTE_GS6  (1646)
#define NOTE_A6  (1744)
#define NOTE_AS6  (1847)
#define NOTE_B6  (1957)
#define NOTE_C7  (2073)
#define NOTE_CS7  (2197)
#define NOTE_D7  (2327)
#define NOTE_DS7  (2466)
#define NOTE_E7  (2613)
#define NOTE_F7  (2768)
#define NOTE_FS7  (2933)
#define NOTE_G7  (3107)
#define NOTE_GS7  (3292)
#define NOTE_A7  (3488)
#define NOTE_AS7  (3695)
#define NOTE_B7  (3915)
#define NOTE_C8  (4147)
#define NOTE_CS8  (4394)
#define NOTE_D8  (4655)
#define NOTE_DS8  (4932)
#define NOTE_E8  (5226)
#define NOTE_F8  (5536)
#define NOTE_FS8  (5866)
#define NOTE_G8  (6214)
#define NOTE_GS8  (6584)
#define NOTE_A8  (6976)
#define NOTE_AS8  (7390)
#define NOTE_B8  (7830)
#else 
#define NOTE_C0  (16.20)
#define NOTE_CS0  (17.17)
#define NOTE_D0  (18.19)
#define NOTE_DS0  (19.27)
#define NOTE_E0  (20.41)
#define NOTE_F0  (21.63)
#define NOTE_FS0  (22.91)
#define NOTE_G0  (24.28)
#define NOTE_GS0  (25.72)
#define NOTE_A0  (27.25)
#define NOTE_AS0  (28.87)
#define NOTE_B0  (30.59)
#define NOTE_C1  (32.41)
#define NOTE_CS1  (34.33)
#define NOTE_D1  (36.37)
#define NOTE_DS1  (38.54)
#define NOTE_E1  (40.83)
#define NOTE_F1  (43.26)
#define NOTE_FS1  (45.83)
#define NOTE_G1  (48.55)
#define NOTE_GS1  (51.44)
#define NOTE_A1  (54.50)
#define NOTE_AS1  (57.74)
#define NOTE_B1  (61.17)
#define NOTE_C2  (64.81)
#define NOTE_CS2  (68.67)
#define NOTE_D2  (72.75)
#define NOTE_DS2  (77.07)
#define NOTE_E2  (81.66)
#define NOTE_F2  (86.51)
#define NOTE_FS2  (91.66)
#define NOTE_G2  (97.11)
#define NOTE_GS2  (102.88)
#define NOTE_A2  (109.00)
#define NOTE_AS2  (115.48)
#define NOTE_B2  (122.35)
#define NOTE_C3  (129.62)
#define NOTE_CS3  (137.33)
#define NOTE_D3  (145.50)
#define NOTE_DS3  (154.15)
#define NOTE_E3  (163.32)
#define NOTE_F3  (173.03)
#define NOTE_FS3  (183.32)
#define NOTE_G3  (194.22)
#define NOTE_GS3  (205.76)
#define NOTE_A3  (218.00)
#define NOTE_AS3  (230.96)
#define NOTE_B3  (244.70)
#define NOTE_C4  (259.25)
#define NOTE_CS4  (274.66)
#define NOTE_D4  (290.99)
#define NOTE_DS4  (308.30)
#define NOTE_E4  (326.63)
#define NOTE_F4  (346.05)
#define NOTE_FS4  (366.63)
#define NOTE_G4  (388.43)
#define NOTE_GS4  (411.53)
#define NOTE_A4  (436.00)
#define NOTE_AS4  (461.93)
#define NOTE_B4  (489.39)
#define NOTE_C5  (518.49)
#define NOTE_CS5  (549.33)
#define NOTE_D5  (581.99)
#define NOTE_DS5  (616.60)
#define NOTE_E5  (653.26)
#define NOTE_F5  (692.11)
#define NOTE_FS5  (733.26)
#define NOTE_G5  (776.86)
#define NOTE_GS5  (823.06)
#define NOTE_A5  (872.00)
#define NOTE_AS5  (923.85)
#define NOTE_B5  (978.79)
#define NOTE_C6  (1036.99)
#define NOTE_CS6  (1098.65)
#define NOTE_D6  (1163.98)
#define NOTE_DS6  (1233.19)
#define NOTE_E6  (1306.52)
#define NOTE_F6  (1384.21)
#define NOTE_FS6  (1466.52)
#define NOTE_G6  (1553.73)
#define NOTE_GS6  (1646.12)
#define NOTE_A6  (1744.00)
#define NOTE_AS6  (1847.70)
#define NOTE_B6  (1957.57)
#define NOTE_C7  (2073.98)
#define NOTE_CS7  (2197.30)
#define NOTE_D7  (2327.96)
#define NOTE_DS7  (2466.39)
#define NOTE_E7  (2613.05)
#define NOTE_F7  (2768.43)
#define NOTE_FS7  (2933.05)
#define NOTE_G7  (3107.45)
#define NOTE_GS7  (3292.23)
#define NOTE_A7  (3488.00)
#define NOTE_AS7  (3695.41)
#define NOTE_B7  (3915.15)
#define NOTE_C8  (4147.95)
#define NOTE_CS8  (4394.60)
#define NOTE_D8  (4655.92)
#define NOTE_DS8  (4932.78)
#define NOTE_E8  (5226.09)
#define NOTE_F8  (5536.85)
#define NOTE_FS8  (5866.09)
#define NOTE_G8  (6214.91)
#define NOTE_GS8  (6584.47)
#define NOTE_A8  (6976.00)
#define NOTE_AS8  (7390.81)
#define NOTE_B8  (7830.30)
#endif