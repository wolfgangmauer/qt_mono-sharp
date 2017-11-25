using System;
using System.Xml.Serialization;
using System.IO;

namespace Qt
{
	[Serializable]
	[XmlRoot("rect", Namespace = "", IsNullable = false)]
	public class Rect
	{
		public Rect()
		{
		}

		public Rect(int x, int y, int w, int h)
		{
			X = x;
			Y = y;
			Width = w;
			Height = h;
		}
		[XmlElement("x")]
		public int X { get; set; }
		[XmlElement("y")]
		public int Y { get; set; }
		[XmlElement("width")]
		public int Width { get; set; }
		[XmlElement("height")]
		public int Height { get; set; }
	}
}

