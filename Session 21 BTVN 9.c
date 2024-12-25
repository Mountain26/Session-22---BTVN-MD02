#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sach {
    char ma[50];
    char ten[50];
    char tacGia[50];
    float gia;
    char theLoai[50];
};

void nhapSach(struct Sach sach[], int *soLuong);
void luuVaoFile(struct Sach sach[], int soLuong);
void layTuFile(struct Sach sach[], int *soLuong);
void hienThiSach(struct Sach sach[], int soLuong);

int main() {
    struct Sach sach[100];
    int soLuong = 0;
    int luaChon;

    do {
        printf("MENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        getchar();

        switch (luaChon) {
            case 1:
                nhapSach(sach, &soLuong);
                break;
            case 2:
                luuVaoFile(sach, soLuong);
                break;
            case 3:
                layTuFile(sach, &soLuong);
                break;
            case 4:
                hienThiSach(sach, soLuong);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (luaChon != 5);

    return 0;
}

void nhapSach(struct Sach sach[], int *soLuong) {
    printf("Nhap so luong sach: ");
    scanf("%d", soLuong);
    getchar();

    for (int i = 0; i < *soLuong; i++) {
        printf("Nhap thong tin cho sach %d:\n", i + 1);
        printf("Ma sach: ");
        fgets(sach[i].ma, sizeof(sach[i].ma), stdin);
        strtok(sach[i].ma, "\n");

        printf("Ten sach: ");
        fgets(sach[i].ten, sizeof(sach[i].ten), stdin);
        strtok(sach[i].ten, "\n");

        printf("Tac gia: ");
        fgets(sach[i].tacGia, sizeof(sach[i].tacGia), stdin);
        strtok(sach[i].tacGia, "\n");

        printf("Gia: ");
        scanf("%f", &sach[i].gia);
        getchar();

        printf("The loai: ");
        fgets(sach[i].theLoai, sizeof(sach[i].theLoai), stdin);
        strtok(sach[i].theLoai, "\n");
    }
}

void luuVaoFile(struct Sach sach[], int soLuong) {
    FILE *file = fopen("struct_sach.bin", "wb");
    if (file == NULL) {
        printf("Loi mo file de ghi!\n");
        return;
    }
    fwrite(sach, sizeof(struct Sach), soLuong, file);
    fclose(file);
    printf("Thong tin sach da duoc luu vao file.\n");
}

void layTuFile(struct Sach sach[], int *soLuong) {
    FILE *file = fopen("struct_sach.bin", "rb");
    if (file == NULL) {
        printf("Loi mo file de doc!\n");
        return;
    }
    *soLuong = fread(sach, sizeof(struct Sach), 100, file);
    fclose(file);
    printf("Thong tin sach da duoc lay tu file.\n");
}

void hienThiSach(struct Sach sach[], int soLuong) {
    printf("Thong tin sach:\n");
    for (int i = 0; i < soLuong; i++) {
        printf("Sach %d:\n", i + 1);
        printf("Ma sach: %s\n", sach[i].ma);
        printf("Ten sach: %s\n", sach[i].ten);
        printf("Tac gia: %s\n", sach[i].tacGia);
        printf("Gia: %.2f\n", sach[i].gia);
        printf("The loai: %s\n", sach[i].theLoai);
        printf("---------------------\n");
    }
}

