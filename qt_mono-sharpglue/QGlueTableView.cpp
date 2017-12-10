#include "QGlueTableView.h"

GlueTableView::GlueTableView(MonoObject* thisObject, QWidget *parent) : QTableView(parent)
{
	_thisObject = thisObject;

	connect(this, &QTableView::pressed, this, &GlueTableView::onpressed);
}

void GlueTableView::onpressed(const QModelIndex& index)
{
	auto klass = mono_object_get_class (_thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnPressed", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "ModelIndex");
		if (eventArgs)
		{
			void *args [1];
			args[0] = (void*)&index;
			auto result = mono_object_new (mono_object_get_domain(_thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			//MonoMethod* method = mono_object_get_virtual_method (_thisObject, eventMethod);
			mono_runtime_invoke(eventMethod, _thisObject, args, NULL);
		}
		else
		{
			printf("Can't create Qt.ModelIndex\n");
			fflush(stdout);
		}
	}
}