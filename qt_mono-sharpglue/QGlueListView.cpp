#include "QGlueListView.h"

GlueListView::GlueListView(MonoObject* thisObject, QWidget *parent) : QListView(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));

	connect(this, &QListView::pressed, this, &GlueListView::onpressed);
}

GlueListView::~GlueListView()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}

void GlueListView::onpressed(const QModelIndex& index)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnPressed", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "ModelIndex");
		if (eventArgs)
		{
			void *args [1];
			args[0] = (void*)&index;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke(eventMethod, mono_gchandle_get_target(_thisObject), args, NULL);
		}
		else
		{
			printf("Can't create Qt.ModelIndex\n");
			fflush(stdout);
		}
	}
}
