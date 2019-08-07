---
title: testLect
layout: page
menuItem: testLect
menuPosition: 4
---

{% if site.docsUrl != "" %}
You can download all required reading in the [Study materials]({{ site.docsUrl }}) at the faculty website.
{% endif %}


{% assign syllabus = (site.testlect | sort: "week") %}
<ul>
{% for wk in syllabus %}
    {% if wk.week == 1 %}
  <li>
  	<a href="{{ site.baseurl }}{{ wk.url }}">{{ wk.title }}</a> 
  	{% for tag in wk.tags %}
  		<b>#{{ tag }}</b>
  	{% endfor %}
  	({{ wk.day }})</li>
    {% endif %}
{% endfor %}
</ul>



---

<ol>
{% assign syllabus = (site.testlect | sort: "week") %}
{% for week in syllabus %}
  <li>
  	<a href="{{ site.baseurl }}{{ week.url }}">{{ week.title }}</a> 
  	{% for tag in week.tags %}
  		<b>#{{ tag }}</b>
  	{% endfor %}
  	({{ week.day }})</li>
{% endfor %}
</ol>

---

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

