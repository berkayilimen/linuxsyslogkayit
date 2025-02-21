# Linux Syslog Kayıt
## Programın Amacı
Bu program son kullanıcının sisteminde kullandığı linux tabanlı işletim sistemindeki syslog dosyalarını okur ve ekrana çıktı olarak yansıtmayı hedefler.


## Programın Kullanım Alanları
- Güvenlik İzleme  :Kullanıcı erişimleri ve güvenlik olayları gibi kritik bilgileri takip eder.
- Günlük Kaydı     :Sistem hatalarını, uyarıları ve durum raporlarını kaydeder.
- Sorun Giderme    : Hataların ve uyarıların kaydedilmesi, sorunların hızlı bir şekilde çözülmesine yardımcı olur.

## Programlama Dili
Bu program tamamen C programlama dili kullanılarak yazılmıştır.

## Kullanım İçin Tavsiye
Kullandığınız linux tabanlı işletim sisteminin desteklediği bir c programlama derleyicisi ile programı tam verimle kullanabilirsiniz.
Örenk olarak : 
- VS Code (Uygulama içerisinden gerekli uzantılar indirilerek c dilindeki programları çalıştırır.) -> [indirme aracı](https://code.visualstudio.com/download)
- CLion  (Eğer bir öğrenci ya da öğretim üyesi -edu.tr mail adresiniz var ise bu uygulamayı ücretsiz bir şekilde kullanabilirsiniz.) -> [indirme aracı](https://www.jetbrains.com/clion/)

## DİKKAT
Kodunuzu çalıştırdığınızda herhangi bir çıktı alamıyor veya hata mesajı alıyorsanız syslog dosya birimi etkinleştirilmemiş olabilir.
Syslog dosya birimini etkinleştirmek için sırasıyla aşağıdaki komutları sisteminizin terminaline (komut istemcisi) yazınız.

Yüklemek için:
*sudo apt update && sudo apt install rsyslog -y (Bu komutun sonuna eklenen '-y', yükleme işlemi sırasında karşınıza çıkacak tüm onay sorularına otomatik olarak 'evet' yanıtı verilir ve işlem hızlanır.)

Yükleme tamamlandıktan sonra aktifleştirmek için:
*sudo systemctl start rsyslog && sudo systemctl enable rsyslog 
