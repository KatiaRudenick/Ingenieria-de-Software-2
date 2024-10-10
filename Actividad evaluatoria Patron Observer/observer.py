from abc import ABC, abstractmethod

# Interfaz Sujeto
class IYouTubeChannel(ABC):
    @abstractmethod
    def subscribe(self, subscriber):
        pass

    @abstractmethod
    def unsubscribe(self, subscriber):
        pass

    @abstractmethod
    def notify_subscribers(self):
        pass

# Interfaz Observador
class ISubscriber(ABC):
    @abstractmethod
    def update(self, video_title):
        pass

# Implemento un Sujeto Concreto 
class YouTubeChannel(IYouTubeChannel):
    def __init__(self, channel_name):
        self.channel_name = channel_name
        self.subscribers = []
        self.latest_video = None

    def subscribe(self, subscriber):
        self.subscribers.append(subscriber)
        print()
        print(f"{subscriber.name} se suscribió al canal {self.channel_name}.")
    

    def unsubscribe(self, subscriber):
        self.subscribers.remove(subscriber)
        print()
        print(f"{subscriber.name} se dió de baja del canal {self.channel_name}.")
        print()

    def notify_subscribers(self):
        for subscriber in self.subscribers:
            subscriber.update(self.latest_video)

    def upload_new_video(self, video_title):
        self.latest_video = video_title
        print()
        print(f"{self.channel_name} subió un nuevo video: {self.latest_video}")
        self.notify_subscribers()

# Implemento un Observador Concreto 
class Subscriber(ISubscriber):
    def __init__(self, name):
        self.name = name

    def update(self, video_title):
        print(f"{self.name} recibió una notificación: Vogue subió '{video_title}'")


if __name__ == "__main__":
    channel = YouTubeChannel("Vogue")

    subscriber1 = Subscriber("Margot Robbie")
    subscriber2 = Subscriber("Taylor Swift")
    subscriber3 = Subscriber("Billie Eilish")

    channel.subscribe(subscriber1)
    channel.subscribe(subscriber2)

    channel.upload_new_video("Emma Chamberlain Gets Ready for Vogue World: Paris")
    
    channel.subscribe(subscriber3)

    channel.upload_new_video("Sabrina Carpenter & Barry Keoghan Get Ready for the Met Gala | Last Looks | Vogue")

    channel.unsubscribe(subscriber1)

    channel.upload_new_video("Kendall Jenner’s Guide to “Spring French Girl“ Makeup | Beauty Secrets | Vogue")
