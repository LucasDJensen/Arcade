using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using UnityEngine;
using System.Text.RegularExpressions;

public class runatstart : MonoBehaviour {
	private SerialPort serialPort;
	private string read;
	private string[] col;
	private static readonly string digitPattern =  "^\\d";
	private Match match;
 
	void Start () {
		serialPort = new SerialPort("COM7", 9600);
		serialPort.Open();
		serialPort.ReadTimeout = 1;
	}
 
	void Update () {
		try {
//			read = serialPort.ReadLine();
//				print(read);

			read = serialPort.ReadLine();
			match = Regex.Match(read, digitPattern);
			if (match.Success) {
				read = read.Substring(0, 2);
				read.Replace(" ", "");
				print(read);
			}
		} catch(System.Exception) {
			
		}
	}
}