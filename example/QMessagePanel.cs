using System;
using Qt;
using System.IO;
using System.Reflection;

namespace TestQtMonoSharp
{
	public class MessagePanel : Dialog
	{
		[UiLoaderAttribute("CAPTION")]
		Label _caption;

		[UiLoaderAttribute("NOW")]
		Label _now;

		[UiLoaderAttribute("NEXT")]
		Label _next;

		[UiLoaderAttribute("REDBUTTON")]
		Label _redlabel;

		[UiLoaderAttribute()]
		Label GREENBUTTON;

		[UiLoaderAttribute()]
		Label YELLOWBUTTON;

		[UiLoaderAttribute()]
		Label BLUEBUTTON;

		public MessagePanel (Qt.Widget parent = null) : base(IntPtr.Zero)
		{
			Raw = new UiLoader(parent).Load( uiFile, this);

			_caption.Text = "Caption";
			_redlabel.Text = "Nein";
			GREENBUTTON.Text = "Ja";
			YELLOWBUTTON.Text = string.Empty;
			BLUEBUTTON.Text ="Optionen";
		}
	}
}

