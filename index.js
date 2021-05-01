var SerialPort = require("serialport");
var robot = require("robotjs");

var portName = process.argv[2];

kicker = new SerialPort(portName, { baudRate: 9600, autoOpen: false });

let Readline = SerialPort.parsers.Readline; // make instance of Readline parser
let parser = new Readline(); // make a new parser to read ASCII lines
kicker.pipe(parser); // pipe the serial stream to the parser

kicker.on("open", function () {
    console.log("Opened CrisisKicker at", portName);
    parser.on('data', function (data) {
        data = data.trim();
        if (data == "on") {
            console.log("Perdal on");
            robot.keyToggle("space", "down");
        } else if (data == "off") {
            console.log("Perdal off");
            robot.keyToggle("space", "up");
        } else {
            console.log("Unrecognized command -", data);
        }
    });
});

kicker.on("error", function (err) {
    console.log("Unable to start serial communication");
    process.exit(1);
})

kicker.open();