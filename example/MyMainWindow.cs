using System;
using Qt;
using System.Diagnostics;

namespace TestQtMonoSharp
{
	public class MyMainWindow : Qt.MainWindow
	{
		public MyMainWindow (Qt.Widget parent = null)
			: base(parent)
		{
			KeyPressEvent += MyMainWindow_KeyPressEvent;
		}

		void MyMainWindow_KeyPressEvent (object sender, KeyEventArgs e)
		{
		}
	}
}

