using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using UnityEngine;
using System.Text.RegularExpressions;

public class runatstart : MonoBehaviour {
	private SerialPort serialPort;
 
	void Start () {
		serialPort = new SerialPort("COM7", 19200);
		serialPort.Open();
		serialPort.ReadTimeout = 1;
	}
 
	void Update () {
		
	}

	float GetPercent() {
		try {	
			return serialPort.ReadLine();
		} catch(System.Exception) {
				
		}
	}
	
}