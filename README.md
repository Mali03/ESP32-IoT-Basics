# ESP32 IoT Basics | ESP32 ile IoT Temelleri
EN - This is a basic IoT project tutorial for smart home automation. This project serves as a step-by-step guide for building an IoT-based remote control system using ESP32. By the end of this tutorial, you'll have a working IoT setup that lets you monitor and control your devices from anywhere in the world! 🌍

TR - Bu, akıllı ev sistemlerinde kullanabileceğiniz bir IoT proje eğitimidir. Bu proje, ESP32 kullanarak IoT temelli uzaktan kontrol sistemleri yapmanız için adım adım klavuzluk yapar. Bu eğitim sayesinde, dünyanın her yerinden IoT projelerinizdeki sensör verilerini izleyebilir ve cihazlarınızı kontrol edebilirsiniz! 🌍

# Languages
You can select your preferred languages below:

- [English](#English)
- [Türkçe](#Türkçe)

# English
As you may know, the ESP32 has limited storage capacity and can not store large amounts of sensor data like most microcontrollers. For this reason, we need to store our sensor data in cloud systems. This is where the **MQTT** protocol comes in. In this project, I used 3 LEDs and 1 LDR to show you how you make it.

![](https://i.imgur.com/cc5GYLq.gif)

## Contents
- [What is MQTT?](#what-is-mqtt)
- [Connection Hardware Components](#connection-hardware-components)
- [Setting up the MQTT Broker](#setting-up-the-mqtt-broker)
- [Code Overview](#code-overview)
- [Seeing datas published from ESP32](#how-to-see-datas-published-from-esp32)
- [Monitoring and controlling the setup from mobile phone](#how-to-monitor-and-control-the-setup-from-mobile-phone)
- [License](#license)
- [Need Help](#need-help)

## What is MQTT? 
MQTT is a protocol built on top of the TCP protocol that helps us easily send and receive data between the ESP32 and the cloud.

![](https://i.imgur.com/4UOfJXT.png)

MQTT is a lightweight messaging protocol based on a publish/subscribe model. Devices publish messages to topics, and other devices subscribe to those topics to receive messages. It uses a broker to manage communication.

![](https://i.imgur.com/OSRb4Su.jpeg)

There are various cloud service to store our datas such as HiveMQ, Mosquitto, and EMQX.

I used HiveMQ because it has **great GUI** and it's **free** for small-scale project.

## Connection Hardware Components

![](https://i.imgur.com/xbhyE2G.png)

## Setting up the MQTT Broker
1. Go to HiveMQ website: https://www.hivemq.com
2. Click on "Start Free" button.

![](https://i.imgur.com/CGblXTH.jpeg)

3. Click on "Sign Up FREE Now" button.

![](https://i.imgur.com/02dpqF2.png)

4. Sign up or log in using your preferred method.

![](https://i.imgur.com/JbVZjrY.png)

5. Go to "Clusters".

![](https://i.imgur.com/yWotc8m.png)

6. Click on "Create Serverless Cluster" button.

![](https://i.imgur.com/320HkhV.png)

7. Click on "Manage Cluster" button.

![](https://i.imgur.com/hALblNG.png)

8. Click on "Access Management" button.

![](https://i.imgur.com/Hm8SjgZ.png)

9. Click on "Edit" button.

![](https://i.imgur.com/twPOCmZ.png)

10. Click on "Add Credentials" button.

![](https://i.imgur.com/PYh2prs.png)

11. After filling in the required fields with your identity, select permission to Publish and Subscribe. Then, click on "Save" button.

![](https://i.imgur.com/JgGDd24.png)

**Everything is done!**

## Code Overview
1. Open **Arduino IDE (I used v2.3.4)**. Then, copy and paste the code in `Esp32-IoT-Basics.ino`.

2. Go to [PubSubClient Library Repository](https://github.com/knolleary/pubsubclient) and download ZIP.

![](https://i.imgur.com/lYcYO0V.png)

3. Go to Arduino IDE and click on `Sketch` -> `Include Library` -> `Add .ZIP Library...`

![](https://i.imgur.com/VjorNgi.png)

4. Select the ZIP file that is downloaded.
5. Configure here (ssid is your wifi name, password is your wifi password, MQTTBroker is broker connection url, MQTTUsername is your credential username, MQTTPassword is your credential password)

![](https://i.imgur.com/64v52Oy.png)

6. Upload the code to ESP32 (while pressing the boot button)

## How to see datas published from ESP32?
Go to "Web Client" and after enterring your credential information click on "Connect" button. 

![](https://i.imgur.com/CwFSw9G.png)

Then, enter your topic and click on "Subscribe" button. (If you want to see all messages, just type "#" there)

![](https://i.imgur.com/PLIgI2d.png)

And then you can see the published messages on "Messages" box.

## How to monitor and control the setup from mobile phone?

1. Download the **`IoT MQTT Panel`** app on IOS/Android.
2. Create a new connection.

![](https://i.imgur.com/jWJbvqL.png)

3. Fill in the required fields (Connection name and client id are up to you, broker id must be `xxx.s1.eu.hivemq.cloud`)

Don't forget to change the port to 8883 and network protocol to TCP-SSL.

![](https://i.imgur.com/Su93CaD.jpeg)

4. Add a dashboard. (Name is up to you)

![](https://i.imgur.com/rgFM6Tf.jpeg)

5. Go to `Additional options`, enter your credential informations.

![](https://i.imgur.com/PUchOpX.jpeg)

6. Click on create button.

7. After it connecting, let's get datas from the app. First, click on "Add Panel" button and select "Text Log" to get LDR datas. (Panel name is up to you, topic is where you want to get messages. And set up the other configuration as you wish.)

![](https://i.imgur.com/71ixdhH.jpeg)

8. In order to add the led switch, click on "+" button. Select "Switch", then, fill in the required fields.

![](https://i.imgur.com/7SKAKUf.jpeg)

## License
This project is licensed under the **MIT License** - see the [LICENSE](https://github.com/Mali03/ESP32-IoT-Basics/blob/main/LICENSE) file for details.

## Need Help
If you need any help contact me on [LinkedIn](https://www.linkedin.com/in/mali03/).

# Türkçe
Bildiğiniz gibi ESP32 kısıtlı bir depolama kapasitesine sahip ve çoğu mikroişlemcilerde olduğu gibi büyük miktarda sensör verilerini bu cihazlarda saklayamazsınız. Bu sebepten ötürü sensör verilerimizi bulut sistemlerinde saklamalıyız. İşte **MQTT** protokolünün devreye girdiği yer burasıdır. Bu projede ben, bunun nasıl yapılacağını 3 led ve 1 LDR kullanarak gösterdim. 

![](https://i.imgur.com/cc5GYLq.gif)

## İçerikler
- [MQTT Nedir?](#mqtt-nedir)
- [Donanım Bileşenlerinin Bağlantısı](#donanım-bileşenlerinin-bağlantısı)
- [MQTT broker'ının ayarlanması.](#mqtt-brokerının-ayarlanması)
- [Kod Yapısı](#kod-yapısı)
- [ESP32 tarafından yayımlanan verileri görme](#esp32-tarafından-yayımlanan-verileri-nasıl-görebiliriz)
- [Mobil telefondan kurulumun izlenmesi ve kontrolü](#mobil-telefondan-kurulum-nasıl-izlenir-ve-kontrol-edilir)
- [Lisans](#lisans)
- [Yardım Almak](#yardıma-ihtiyacın-var-mı)

## MQTT Nedir?
MQTT, ESP32 ile bulut arasında verileri kolayca gönderip almamızı sağlayan TCP protokolü üzerine kurulu bir protokoldür.

![](https://i.imgur.com/4UOfJXT.png)

MQTT, yayınla/abone ol modeline dayalı düşük maliyetli bir mesajlaşma protokolüdür. Aygıtlar konulara mesajlar yayınlar ve diğer aygıtlar mesajları almak için bu konulara abone olur. İletişimi yönetmek için bir broker kullanır.

![](https://i.imgur.com/OSRb4Su.jpeg)

HiveMQ, HiveMQ, Mosquitto, ve EMQX gibi verilerimizi saklayacağımız çeşitli bulut servisleri var.

Ben HiveMQ kullandım çünkü güzel bir arayüze sahip ve küçük çaplı projeler için ücretsiz.

## Donanım Bileşenlerinin Bağlantısı

![](https://i.imgur.com/xbhyE2G.png)

## MQTT broker'ının ayarlanması.
1. HiveMQ'nun sitesine gidin: https://www.hivemq.com
2. "Start Free" butonuna tıklayın.

![](https://i.imgur.com/CGblXTH.jpeg)

3. "Sign Up FREE Now" butonuna tıklayın.

![](https://i.imgur.com/02dpqF2.png)

4. Kayıt olun veya bir hesabınızla giriş yapın.

![](https://i.imgur.com/JbVZjrY.png)

5. "Clusters" bölümüne gidin.

![](https://i.imgur.com/yWotc8m.png)

6. "Create Serverless Cluster" butonuna tıklayın.

![](https://i.imgur.com/320HkhV.png)

7. "Manage Cluster" butonuna tıklayın.

![](https://i.imgur.com/hALblNG.png)

8. "Access Management" butonuna tıklayın.

![](https://i.imgur.com/Hm8SjgZ.png)

9. "Edit" butonuna tıklayın.

![](https://i.imgur.com/twPOCmZ.png)

10. "Add Credentials" butonuna tıklayın.

![](https://i.imgur.com/PYh2prs.png)

11. Boşlukları kimlik bilgilerinizle doldurduktan sonra yetkilerinizi Publish and Subscribe olarak belirleyin. Daha sonra, "Save" butonuna tıklayın.

![](https://i.imgur.com/JgGDd24.png)

**Herşey tamamlandı!**

## Kod Yapısı
1. **Arduino IDE'yi (Ben 2.3.4 sürümünü kullandım)** açın. Daha sonra, `Esp32-IoT-Basics.ino`'deki kodu kopyalayıp yapıştırın.

2. [PubSubClient Kütüphane Repository'sine](https://github.com/knolleary/pubsubclient) gidin ve ZIP olarak yükleyin.

![](https://i.imgur.com/lYcYO0V.png)

3. Arduino IDE'ye gidin ve `Sketch` -> `Include Library` -> `Add .ZIP Library...` butonuna tıklayın.

![](https://i.imgur.com/VjorNgi.png)

4. Yüklediğiniz ZIP dosyasını seçin.
5. Burayı düzenleyin (ssid wifi'nizin adı, password wifi'nizin şifresi, MQTTBroker broker bağlantı linki, MQTTUsername kimlik bilgilerindeki isim, MQTTPassword kimlik bilgilerindeki şifre)

![](https://i.imgur.com/64v52Oy.png)

6. **ESP32**'ye kodu yükleyin (boot butonuna basılı tutarken)

## ESP32 tarafından yayımlanan verileri nasıl görebiliriz?
"Web Client" bölümüne gidin ve kimlik bilgilerinizi doldurduktan sonra "Connect" butonuna tıklayın.

![](https://i.imgur.com/CwFSw9G.png)

Daha sonra, konuyu girin ve "Subscribe" butonuna tıklayın. (Eğer tüm mesajları görmek istiyorsanız, sadece # yazın)

![](https://i.imgur.com/PLIgI2d.png)

Paylaşılan mesajları "Messages" kutusunda görebilirsiniz.

## Mobil telefondan kurulum nasıl izlenir ve kontrol edilir?

1. **`IoT MQTT Panel`** uygulamasını iOS/Android cihazınıza indirin.
2. Yeni bir bağlantı oluşturun

![](https://i.imgur.com/jWJbvqL.png)

3. Gerekli alanları doldurun (Connection name ve client id kısmına istediğinizi yazabilirsiniz, broker id `xxx.s1.eu.hivemq.cloud` şeklindeki broker idniz olmalı)

Portunuzu 8883 olarak değişmeyi ve ağ protokolünü TCP-SSL olarak değiştirmeyi unutmayın.

![](https://i.imgur.com/Su93CaD.jpeg)

4. Bir dashboard ekleyin. (Name kısmına istediğinizi yazabilirsiniz)

![](https://i.imgur.com/rgFM6Tf.jpeg)

5. `Additional options` bölümüne gidin, kimlik bilgilerinizi girin.

![](https://i.imgur.com/PUchOpX.jpeg)

6. "Create" butonuna tıklayın.

7. Bağlandıkdan sonra, uygulamadan verileri alalım. Öncelikle "Add Panel" butonuna tıklayın ve LDR verilerini almak için "Text Log"'u seçin. (Panel name kısmına istediğinizi yazabilirsiniz, topic nereden veri toplamak istediğiniz. Diğer ayarları istediğiniz gibi ayarlayabilirsiniz)

![](https://i.imgur.com/71ixdhH.jpeg)

8. Led kontrolünü yapmak üzere anahtar eklemek için "+" butonuna tıklayın. "Switch"'i seçin ve gerekli alanları doldurun.

![](https://i.imgur.com/7SKAKUf.jpeg)

## Lisans
Bu proje **MIT Lisansı** ile lisanslanmıştır - detaylar için [LICENSE](https://github.com/Mali03/ESP32-IoT-Basics/blob/main/LICENSE) dosyasına göz atın.

## Yardıma ihtiyacın var mı?
Yardıma ihtiyacın varsa benimle [LinkedIn](https://www.linkedin.com/in/mali03/) üzerinden iletişime geçebilirsin.
