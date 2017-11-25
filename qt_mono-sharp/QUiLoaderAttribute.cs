using System;

namespace Qt
{
	[AttributeUsageAttribute(AttributeTargets.Field)]
	public class UiLoaderAttribute : Attribute
	{
		public UiLoaderAttribute ()
		{
		}

		public UiLoaderAttribute (string fieldName)
		{
			FieldName = fieldName;
		}

		public string FieldName { get; private set; }
	}
}

