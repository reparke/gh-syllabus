---
title: Lecture
layout: page
menuItem: Lecture
menuPosition: 5

---

{% if site.docsUrl != "" %}
DDDDD can download all required reading in the [Study materials]({{ site.docsUrl }}) at the faculty website.
{% endif %}

There's something that needs to be told. Maybe.

<ol>
{% assign syllabus = (site.syllabus | sort: "week") %}
{% for week in syllabus %}
  <li>
  	<a href="{{ site.baseurl }}{{ week.url }}">{{ week.title }}</a> 
  	{% for tag in week.tags %}
  		<b>#{{ tag }}</b>
  	{% endfor %}
  	({{ week.day }})</li>
{% endfor %}
</ol>
<ol>
{% assign lecture = (site.lecture | sort: "week") %}
{% for week in lecture %}
  <li>
  	<a href="{{ site.baseurl }}{{ week.url }}">{{ week.title }}</a> 
  	{% for tag in week.tags %}
  		<b>#{{ tag }}</b>
  	{% endfor %}
  	({{ week.day }})</li>
{% endfor %}
</ol>

