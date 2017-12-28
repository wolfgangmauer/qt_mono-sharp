using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class ListWidgetItem
	{
		public enum ItemType
		{
			Type = 0,
			UserType = 1000
		}

		public IntPtr Handle { get; private set; }

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_listwidgetitem_new (IntPtr icon, string text, IntPtr view, ItemType type);
		public ListWidgetItem (Icon icon, string text, ListWidget view = null, ItemType type = ItemType.Type)
		{
			Handle = qt_listwidgetitem_new (icon.Handle, text, view == null ? IntPtr.Zero : view.Handle, type);
		}

		public ListWidgetItem (IntPtr raw)
		{
			Handle = raw;
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern string qt_listwidgetitem_text_get (IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_listwidgetitem_text_set (IntPtr raw, string text);
		public string Text
		{
			get 
			{
				return qt_listwidgetitem_text_get (Handle);
			}
			set
			{
				qt_listwidgetitem_text_set (Handle, value);
			}
		}
	}
}

