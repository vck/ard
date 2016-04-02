#!/usr/bin/env python
# coding=utf-8

from flask import Flask
from flask import jsonify
import serial
import devicelist


board = devicelist
app = Flask(__name__)

try:
    arduino = serial.Serial(board.get_serial()[0], 9600 )
    print "[+] status: connected to arduino board"
except:
    print "[-] unable to connect to arduino board"

@app.route("/on")
def TurnOn():
    arduino.write("on")
    return jsonify(data="on", status="success")

@app.route("/")
def IndexPage():
	return jsonify(status="server-ready")

if __name__ == "__main__":
    app.run(port=1234, host="0.0.0.0", threaded=True)

