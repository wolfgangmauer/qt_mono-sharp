using System;
using Qt;
using System.IO;
using System.Reflection;

namespace TestQtMonoSharp
{
	public class SplashScreen : Widget
	{
		[UiLoader()]
		VBoxLayout verticalLayout_2;

		[UiLoader()]
		VBoxLayout verticalLayout;

		[UiLoader()]
		ProgressBar progressBar;

		[UiLoader()]
		Frame frame;

		[UiLoader()]
		Label label;

		public SplashScreen (Qt.Widget parent = null)
			: base (parent, "./splashscreen.ui", (WindowType.WindowStaysOnTopHint | WindowType.SplashScreen))
		{
			Geometry = Style.AlignedRect(LayoutDirection.LeftToRight, Alignment.AlignCenter, Size, Qt.Application.Desktop.Geometry);
//			if (string.IsNullOrEmpty(ObjectName))
//				ObjectName = "Dialog";
//			Resize(987, 146);
//			Font = new Font("Ubuntu Condensed", 30);
//			WindowOpacity = (0.9);
//
//			verticalLayout_2 = new VBoxLayout(this);
//			verticalLayout_2.ObjectName = "verticalLayout_2";
//			verticalLayout_2.SetContentsMargins(9, 9, 9, -1);
//
//			frame = new Frame(this);
//			frame.ObjectName = "frame";
//			frame.FrameShape = Frame.Shape.Box;
//
//			verticalLayout = new VBoxLayout(frame);
//			verticalLayout.Spacing = (10);
//			verticalLayout.ObjectName = "verticalLayout";
//
//			label = new Label(frame);
//			label.ObjectName = "label";
//			label.Text = "TextLabel";
//			SizePolicy sizePolicy = new SizePolicy(Policy.Minimum, Policy.Minimum);
//			sizePolicy.HorizontalStretch = (0);
//			sizePolicy.VerticalStretch = (0);
//			label.SizePolicy = sizePolicy;
//			label.Alignment = Alignment.AlignCenter;
//			verticalLayout.AddWidget(label);
//
//			progressBar = new ProgressBar(frame);
//			progressBar.ObjectName = "progressBar";
			progressBar.Value = 50;
//			verticalLayout.AddWidget(progressBar);
//
//			verticalLayout_2.AddWidget(frame);

			KeyPressEvent += SplashScreen_KeyPressEvent;
//			CloseEvent += SplashScreen_CloseEvent;
		}

		public void SetRange(int min, int max)
		{
			progressBar.SetRange (min, max);
		}

		public void SetValue(int val)
		{
			progressBar.Value = val;
		}

		//
		void SplashScreen_KeyPressEvent (object sender, KeyEvent e)
		{
			if (e.Text == "+")
			{
				progressBar.Value++;
			}
			else if (e.Text == "-")
			{
				progressBar.Value--;
			}
		}
//
//		void SplashScreen_CloseEvent (object sender, Qt.CloseEvent e)
//		{
//			e.Accept ();
//		}
	}
}

