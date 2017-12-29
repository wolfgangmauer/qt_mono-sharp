using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Xml.Serialization;

namespace Qt
{
	public class ComboBox : Widget
	{
		public event EventHandler<int> ActivatedByIndex;
		public event EventHandler<string> ActivatedByString;

		public ComboBox (IntPtr raw) : base(raw) {}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_combobox_new (ComboBox thisObject, IntPtr parent);
		public ComboBox (Widget parent)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_combobox_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_combobox_sizehint_get (IntPtr raw);
		public new Size SizeHint
		{
			get{ return new Size(qt_combobox_sizehint_get(Handle));}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_combobox_modelcolumn_get (IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_combobox_modelcolumn_set (IntPtr raw, int visibleColumn);
		public int ModelColumn
		{
			get{ return qt_combobox_modelcolumn_get (Handle); }
			set{ qt_combobox_modelcolumn_set (Handle, value); }
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_combobox_model_get (IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_combobox_model_set (IntPtr raw, IntPtr model);
		public StandardItemModel Model
		{
			get { return new StandardItemModel (qt_combobox_model_get (Handle)); }
			set { qt_combobox_model_set (Handle, value.Handle); }
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern string qt_combobox_itemtext_get (IntPtr raw, int index);
		public string GetItemText(int index)
		{
			return qt_combobox_itemtext_get (Handle, index);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_combobox_itemtext_set (IntPtr raw, int index, string text);
		public void SetItemText(int index, string text)
		{
			qt_combobox_itemtext_set (Handle, index, text);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_combobox_itemicon_get (IntPtr raw, int index);
		public Icon GetItemIcon(int index)
		{
			return new Icon(qt_combobox_itemicon_get (Handle, index));
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_combobox_itemicon_set (IntPtr raw, int index, IntPtr icon);
		public void SetItemIcon(int index, Icon icon)
		{
			qt_combobox_itemicon_set (Handle, index, icon.Handle);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern object qt_combobox_itemdata_get (IntPtr raw, int index, ItemDataRole role);
		public object GetItemData(int index, ItemDataRole role = ItemDataRole.UserRole)
		{
			return qt_combobox_itemdata_get (Handle, index, role);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_combobox_itemdata_set (IntPtr raw, int index, object data, ItemDataRole role);
		public void SetItemData(int index, object data, ItemDataRole role = ItemDataRole.UserRole)
		{
			qt_combobox_itemdata_set (Handle, index, data, role);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_combobox_item_text_add (IntPtr raw, string text, object data);
		public void AddItem(string text, object userData = default(object))
		{
			qt_combobox_item_text_add (Handle, text, userData);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_combobox_item_icon_text_add (IntPtr raw, IntPtr icon, string text, object data);
		public void AddItem(Icon icon, string text, object userData = default(object))
		{
			qt_combobox_item_icon_text_add (Handle, icon.Handle, text, userData);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_combobox_item_text_insert (IntPtr raw, string text, object data);
		public void InsertItem(int index, string text, object userData = default(object))
		{
			qt_combobox_item_text_insert(Handle, text, userData);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_combobox_item_icon_text_insert (IntPtr raw, IntPtr icon, string text, object data);
		public void InsertItem(int index, Icon icon, string text, object userData = default(object))
		{
			qt_combobox_item_icon_text_insert(Handle, icon.Handle, text, userData);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_combobox_separator_insert (IntPtr raw, int index);
		public void InsertSeparator(int index)
		{
			qt_combobox_separator_insert (Handle, index);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_combobox_item_remove (IntPtr raw, int index);
		public void RemoveItem(int index)
		{
			qt_combobox_item_remove (Handle, index);
		}

		private void OnActivatedByIndex (int index)
		{
			var tmp = ActivatedByIndex;
			tmp?.Invoke (this, index);
		}

		private void OnActivatedByString (string text)
		{
			var tmp = ActivatedByString;
			tmp?.Invoke (this, text);
		}
	}
}