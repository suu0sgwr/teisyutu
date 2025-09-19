/*『ポート番号と開閉有無を入力し、オープンポートのみ表示するプログラム』

1)以下のデータをまとめた構造体portnumを定義
float型  portnum
char型配列 service1（最大8文字）
char型配列 state（最大8文字）
char型配列 service2（最大8文字）
2)ファイル「T325043_input.txt」データを読み取り
service1  state  service2はスペース区切り
※ファイルが開けなければその旨を表示
3)show_open関数を実行
引数： portscan型配列p，配列サイズn
戻り値： なし
内部での処理： p内のn個の要素のうち，open と一致する文字列の行を表示し、ファイル「output.txt」にコピーする

*/
//追加

#include <stdio.h>
#include <string.h>

typedef struct // 1.構造体portscanの定義
{
    int portnum;
    char service1[8];
    char state[8];
    char service2[8];
} portscan;

void show_open(portscan p[], int n); // プロトタイプ宣言

int main(void)
{

    int i = 0;
    portscan p[20]; // データ行数
    FILE *fpr = fopen("T325043_input.txt", "r");
    // FILE *fpr = fopen("temp.txt", "r");
    if (fpr == NULL)
    {
        printf("ファイルが開けませんでした\n");
        return 0;
    }
    fscanf(fpr, "%s  %s  %s", p[i].service1, p[i].state, p[i].service2);
    i++;
    while (fscanf(fpr, "%d %s  %s  %s", &p[i].portnum, p[i].service1, p[i].state, p[i].service2) != EOF) // 記入　最初から最後まで
    {
        i++;
    }

    show_open(p, i); // 引数 最後の行まで

    fclose(fpr);
    return 0;
}

void show_open(portscan p[], int n) // 引数： person型配列p，配列サイズn
{
    int i;
    FILE *fpw = fopen("output.txt", "w");

    printf("%s\t\t%s\t%s\n", p[0].service1, p[0].state, p[0].service2); // 表示する
    fprintf(fpw,"%s\t\t\t%s\t%s\n", p[0].service1, p[0].state, p[0].service2); // 表示する

    for (i = 1; i < n; i++) // iがnまで
    {
        if (strcmp(p[i].state, "open") == 0) // 文字列が一致する場合
        {
            printf("%6d\t%s\t%s\t%s\n", p[i].portnum, p[i].service1, p[i].state, p[i].service2);       // 表示する
            fprintf(fpw, "%6d\t%s\t%s\t%s\n", p[i].portnum, p[i].service1, p[i].state, p[i].service2); // 書き込む
        }
    }

    fclose(fpw);
}