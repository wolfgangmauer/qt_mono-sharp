using System;
using Qt;
using System.Diagnostics;

namespace TestQtMonoSharp
{
	public class MyMainWindow : Qt.MainWindow
	{
		[UiLoader ()]
		TableView tableView;

		public MyMainWindow (Qt.Widget parent = null)
			: base (parent, "./mainwindow.ui")
		{
			//tableView = new TableView (this);
		}

		protected override void OnKeyPress (KeyEvent ev)
		{
			base.OnKeyPress (ev);
		}
	}
}

