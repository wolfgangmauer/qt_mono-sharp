using System;
using Qt;
using System.IO;
using System.Reflection;

namespace TestQtMonoSharp
{
	public class SplashScreen : Dialog
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
			: base (parent, "./splashscreen.ui")
		{
//			if (string.IsNullOrEmpty(ObjectName))
//				ObjectName = "Dialog";
//			Resize(987, 146);
//			Font = new Font("Ubuntu Condensed", 30);
//			WindowOpacity = (0.9);
//
//			verticalLayout_2 = VBoxLayout.CreateWithRaw(this);
//			verticalLayout_2.ObjectName = "verticalLayout_2";
//			verticalLayout_2.SetContentsMargins(9, 9, 9, -1);
//
//			frame = Frame.CreateWithRaw(this);
//			frame.ObjectName = "frame";
//			frame.FrameShape = Frame.Shape.Box;
//
//			verticalLayout = VBoxLayout.CreateWithRaw(frame);
//			verticalLayout.Spacing = (10);
//			verticalLayout.ObjectName = "verticalLayout";
//
//			label = Label.CreateWithRaw(frame);
//			label.ObjectName = "label";
//			label.Text = "TextLabel";
//			SizePolicy sizePolicy = new SizePolicy(Policy.Minimum, Policy.Minimum);
//			sizePolicy.HorizontalStretch = (0);
//			sizePolicy.VerticalStretch = (0);
//			label.SizePolicy = sizePolicy;
//			label.Alignment = Alignment.AlignCenter;
//			verticalLayout.AddWidget(label);
//
//			progressBar = ProgressBar.CreateWithRaw(frame);
//			progressBar.ObjectName = "progressBar";
//			progressBar.Value = 0;
//			verticalLayout.AddWidget(progressBar);
//
//			verticalLayout_2.AddWidget(frame);

			KeyPressEvent += SplashScreen_KeyPressEvent;
			CloseEvent += SplashScreen_CloseEvent;
		}

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

		void SplashScreen_CloseEvent (object sender, Qt.CloseEvent e)
		{
			e.Accept ();
		}
	}
}

