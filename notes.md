
# notes

For learning!

The only networking portion I am interested in is UDP, specifically shooting messages at my server.

Ideally this would be for logging, I don't intend to send data the reverse direction, and so I'm not worried about failure.  Whatever I can get is good.

So we can do something like this:

    bool userConsent = true;// give them a checkbox from the UI (eventually)

    sf::UdpSocket socket;
    sf::IpAddress serverIp("webserver.com");
    unsigned short port;
    socket.bind(port);

    if (userConfirmedSubmitData) {
        socket.send(text, length_of_text + 1, serverIp, port)
    }

They even make it way easier to transmit lots of data, packets!

    sg::Packet packet;

    packet << someData;
    socket.send(packet);

_It was not clear how to specify where the data is to be sent to (eg. serverIp and port to use).

