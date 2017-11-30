using System;
using Qt;
using System.Diagnostics;

namespace TestQtMonoSharp
{
	public class MyMainWindow : Qt.MainWindow
	{
		public MyMainWindow (Qt.Widget parent = null)
			: base(parent, "./mainwindow.ui")
		{
		}

		protected override void OnKeyPress (KeyEvent ev)
		{
			base.OnKeyPress (ev);
		}
	}
}

