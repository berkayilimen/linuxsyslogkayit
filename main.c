#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_SATIR 512  // Maksimum satır uzunluğu

// Bağlı liste düğüm yapısı
struct LogDugumu {
    char mesaj[MAKS_SATIR];  // Log mesajı
    struct LogDugumu* sonraki;    // Sonraki düğüm
};

// Yeni düğüm oluşturma fonksiyonu
struct LogDugumu* dugumOlustur(const char* logMesaji) {
    struct LogDugumu* yeniDugum = (struct LogDugumu*)malloc(sizeof(struct LogDugumu));
    if (!yeniDugum) {
        printf("Bellek tahsis hatası!\n");
        return NULL;
    }
    strncpy(yeniDugum->mesaj, logMesaji, MAKS_SATIR);  // Log mesajını kopyala
    yeniDugum->sonraki = NULL;  // Sonraki düğüm işaretçisi null
    return yeniDugum;
}

// Syslog verisini oku ve bağlı listeye ekle
struct LogDugumu* syslogOku() {
    FILE* dosya = fopen("/var/log/syslog", "r");  // Syslog dosyasını aç
    if (!dosya) {
        // Eğer dosya açılamazsa, root yetkisi gerekebilir
        printf("Syslog dosyası açılamadı! Root yetkisi gerekebilir.\n");
        return NULL;
    }

    struct LogDugumu* bas = NULL;  // Listeyi başlat
    struct LogDugumu* son = NULL;  // Son düğümü izlemek için
    char satir[MAKS_SATIR];  // Satırları tutmak için geçici buffer

    // Dosyadaki her satırı oku
    while (fgets(satir, sizeof(satir), dosya)) {
        struct LogDugumu* yeniDugum = dugumOlustur(satir);  // Yeni düğüm oluştur
        if (!bas) {
            bas = yeniDugum;  // İlk düğümü ekle
            son = yeniDugum;  // İlk düğüm baş ve son
        } else {
            son->sonraki = yeniDugum;  // Son düğüme yeni düğümü ekle
            son = yeniDugum;  // Son düğüm olarak işaretle
        }
    }

    fclose(dosya);  // Dosyayı kapat
    return bas;  // Listeyi döndür
}

// Bağlı listeyi ekrana yazdır
void loglariYazdir(struct LogDugumu* bas) {
    struct LogDugumu* temp = bas;
    while (temp) {
        printf("%s", temp->mesaj);  // Log mesajını yazdır
        temp = temp->sonraki;  // Sonraki düğüme geç
    }
}

// Belleği temizle (Bağlı listeyi serbest bırak)
void listeyiBosalt(struct LogDugumu* bas) {
    struct LogDugumu* temp;
    while (bas) {
        temp = bas;
        bas = bas->sonraki;
        free(temp);  // Belleği serbest bırak
    }
}

int main() {
    struct LogDugumu* logListesi = syslogOku();  // Syslog'u oku ve listeyi oluştur
    if (logListesi) {
        printf("=== SYSLOG KAYITLARI ===\n");
        loglariYazdir(logListesi);  // Bağlı listedeki logları yazdır
        listeyiBosalt(logListesi);  // Belleği temizle
    }
    return 0;
}
