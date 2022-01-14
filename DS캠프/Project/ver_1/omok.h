#ifndef __OMOK_H__
#define __OMOK_H__

void printOrigin();  // 시작멘트 출력 (오목의 기원에 대하여 ,,)
int askAge(); // 나이 묻기
void addPoint(int list[][15], int user, int x, int y); // 배열에 점 추가
void drawMap(int list[][15]); // 바둑판 그리기
int checkOmok(int list[][15]); // 오목인지 확인
void printCredit(); // 엔딩크레딧 출력 (만든이)

#endif