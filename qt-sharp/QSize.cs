using System;
using System.Xml.Serialization;

namespace Qt
{
	[Serializable]
	[XmlRoot("size", Namespace = "", IsNullable = false)]
    public class Size
    {
        public Size()
        {
        }

        public Size(int w, int h)
        {
            Width = w;
            Height = h;
        }

		[XmlElement("width")]
        public int Width { get; set; }
		[XmlElement("height")]
        public int Height { get; set; }
    }
}
