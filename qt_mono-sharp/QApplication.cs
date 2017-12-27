using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Reflection;
using System.Collections.Generic;

namespace Qt
{
    public class Application : GuiApplication
    {
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_application_new(Application thisObject, string[] argv);

		public Application(string[] argv) : base(IntPtr.Zero)
        {
			if (!monointernal_init)
				InitMonoInternal ();
			var ass = Assembly.GetEntryAssembly ().CodeBase.Replace("file://", string.Empty);
			var list = new List<string> (argv);
			list.Insert (0, ass);
			Raw = qt_application_new(this, list.ToArray());
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern int qt_application_exec(IntPtr raw);
		public int Exec()
		{
			var handle = GetObjectFromRaw (Handle);
			int retVal = qt_application_exec (handle.Handle);
			return retVal;
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_application_desktop_get ();
		public static DesktopWidget Desktop
		{
			get
			{
				return new DesktopWidget (qt_application_desktop_get ());
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_application_postevent (IntPtr receiver, IntPtr _event, int priority);
		public static void PostEvent(Object receiver, Event _event, int priority = (int)EventPriority.NormalEventPriority)
		{
			qt_application_postevent (receiver.Handle, _event.Handle, priority);
		}

		public static MainWindow MainWindow {
			get;
			set;
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_application_activewindow_get ();
		public static Widget ActiveWindow
		{
			get
			{
				var ptr = qt_application_activewindow_get ();
				if (ptr == IntPtr.Zero)
					return null;
				var retVal = GetObjectFromRaw (ptr) as Widget;
				return retVal;
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_application_events_process (EventLoop.ProcessEventsFlag flags);
		public static void ProcessEvents(EventLoop.ProcessEventsFlag flags = EventLoop.ProcessEventsFlag.AllEvents)
		{
			qt_application_events_process (flags);
		}

		internal class InvokeCB 
		{
			EventHandler d;
			object sender;
			EventArgs args;

			internal InvokeCB (EventHandler d)
			{
				this.d = d;
				args = EventArgs.Empty;
				sender = this;
			}

			internal InvokeCB (EventHandler d, object sender, EventArgs args)
			{
				this.d = d;
				this.args = args;
				this.sender = sender;
			}

			internal bool Invoke ()
			{
				d (sender, args);
				return false;
			}
		}

		public static void Invoke (EventHandler d)
		{
			InvokeCB icb = new InvokeCB (d);
			GLib.Timeout.Add (0, new GLib.TimeoutHandler (icb.Invoke));
		}

		public static void Invoke (object sender, EventArgs args, EventHandler d)
		{
			InvokeCB icb = new InvokeCB (d, sender, args);
			GLib.Timeout.Add (0, new GLib.TimeoutHandler (icb.Invoke));
		}
    }
}
