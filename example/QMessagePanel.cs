using System;
using Qt;
using System.IO;
using System.Reflection;

namespace TestQtMonoSharp
{
	public class MessagePanel : Dialog
	{
		[UiLoader("CAPTION")]
		Label _caption;

		[UiLoader("NOW")]
		Label _now;

		[UiLoader("NEXT")]
		Label _next;

		[UiLoader("REDBUTTON")]
		Label _redlabel;

		[UiLoader()]
		Label GREENBUTTON;

		[UiLoader()]
		Label YELLOWBUTTON;

		[UiLoader()]
		Label BLUEBUTTON;

		public MessagePanel (Qt.Widget parent = null) : base(IntPtr.Zero)
		{
			Raw = new UiLoader(this).Load(uiFile);

			_caption.Text = "Caption";
			_redlabel.Text = "Nein";
			GREENBUTTON.Text = "Ja";
			YELLOWBUTTON.Text = string.Empty;
			BLUEBUTTON.Text ="Optionen";
		}
	}
}

